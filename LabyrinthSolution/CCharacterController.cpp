#include "CCharacterController.h"
#include "PlayerCharacter.h"

CCharacterController::CCharacterController()
{
    dirty = false;

    keySets.push( CKeySet(Qt::Key_T, Qt::Key_G, Qt::Key_F, Qt::Key_H));
    keySets.push( CKeySet(Qt::Key_I, Qt::Key_K, Qt::Key_J, Qt::Key_L));
    keySets.push( CKeySet(Qt::Key_Up, Qt::Key_Down, Qt::Key_Left, Qt::Key_Right));
    keySets.push( CKeySet(Qt::Key_W, Qt::Key_S, Qt::Key_A, Qt::Key_D));
}

CKeySet CCharacterController::GetKeySet()
{
    CKeySet retVal = keySets.top();
    keySets.pop();
    return retVal;
}

int CCharacterController::GetKeySetsLeft()
{
    return keySets.size();
}

int CCharacterController::GetCurrentPosition(int characterIndex)
{
    dirty = false;
    return this->characters[characterIndex].GetPosition();
}

void CCharacterController::MessUp()
{
    dirty = true;
}

void CCharacterController::MovePlayer(int characterIndex, Direction dir)
{
   dirty = this->characters[characterIndex].Move(dir);
}

bool CCharacterController::IsDirty()
{
    return dirty;
}

void CCharacterController::AddPlayer(CLabyrinthController* lab)
{
   characters.push_back(CPlayerCharacter(lab, lab->GetStartPoint(), Direction::All, new QBrush(Qt::yellow, Qt::SolidPattern)));
}

void CCharacterController::AddPlayer(CLabyrinthController* lab, int startPoint, QBrush* brush)
{
   characters.push_back(CPlayerCharacter(lab, startPoint, Direction::All, brush));
}

void CCharacterController::AddPlayer(CLabyrinthController* lab, int startPoint, CKeySet cmds, QBrush* brush)
{
   characters.push_back(CPlayerCharacter(lab, startPoint, cmds, Direction::All, brush));
}

void CCharacterController::HandleInput(int key)
{
    for (int i = 0; i < characters.size(); i++)
	{
        CCharacterCommand* cmd = characters.at(i).GetKeySet()->Handle(key);
        if(cmd != nullptr)
        {
            cmd->execute(*this, i);
        }
	}
}

QBrush* CCharacterController::GetBrushOfPlayer(int characterIndex)
{
    return characters.at(characterIndex).GetBrush();
}

list<int>* CCharacterController::GetTraceLine(int characterIndex)
{
    return characters.at(characterIndex).GetTraceLine();
}

int CCharacterController::GetPlayerCount()
{
    return characters.size();
}
