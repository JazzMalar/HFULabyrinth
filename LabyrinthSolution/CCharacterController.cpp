#include "CCharacterController.h"
#include "PlayerCharacter.h"

CCharacterController::CCharacterController()
{
    dirty = false;

    commandSets.push( CCommandSet(Qt::Key_W, Qt::Key_S, Qt::Key_A, Qt::Key_D));
    commandSets.push( CCommandSet(Qt::Key_Up, Qt::Key_Down, Qt::Key_Left, Qt::Key_Right));
    commandSets.push( CCommandSet(Qt::Key_I, Qt::Key_K, Qt::Key_J, Qt::Key_L));
    commandSets.push( CCommandSet(Qt::Key_T, Qt::Key_G, Qt::Key_F, Qt::Key_H));
}

CCommandSet CCharacterController::GetCommandSet()
{
    CCommandSet retVal = commandSets.top();
    commandSets.pop();
    return retVal;
}

int CCharacterController::GetCommandsLeft()
{
    return commandSets.size();
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

void CCharacterController::AddPlayer(CLabyrinthController* lab, int startPoint, CCommandSet cmds, QBrush* brush)
{
   characters.push_back(CPlayerCharacter(lab, startPoint, cmds, Direction::All, brush));
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
