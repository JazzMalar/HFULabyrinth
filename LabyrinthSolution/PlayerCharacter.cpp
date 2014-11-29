#include "PlayerCharacter.h"


CPlayerCharacter::CPlayerCharacter(CLabyrinthController* lab, int startPoint, Direction allowedDirection, QBrush* brush)
{
	this->allowedDirection = allowedDirection;
	this->labyrinth = lab; 
	this->position = startPoint; 
    this->brush = brush;
}

CPlayerCharacter::CPlayerCharacter(CLabyrinthController* lab, int startPoint, CKeySet cmds, Direction allowedDirection, QBrush* brush)
{
    this->allowedDirection = allowedDirection;
    this->keySet = cmds;
    this->labyrinth = lab;
    this->position = startPoint;
    this->brush = brush;
}

CPlayerCharacter::~CPlayerCharacter()
{
}

CKeySet* CPlayerCharacter::GetKeySet()
{
	return &this->keySet; 
}

bool CPlayerCharacter::Move(Direction dir)
{
    bool changed = false;

    if (this->allowedDirection != Direction::All && dir != this->allowedDirection)
	{
        return changed;
	}

	if (labyrinth->IsWallDestroyed(position, dir))
	{
		trace.push_back(position);
        position = labyrinth->GetNextCell(position, dir);
        changed = true;
	}

    return changed;

}

QBrush* CPlayerCharacter::GetBrush()
{
    return this->brush;
}

int CPlayerCharacter::GetPosition()
{
    return this->position;
}

int CPlayerCharacter::GetSteps()
{
    return steps;
}

list<int>* CPlayerCharacter::GetTraceLine()
{
    return &this->trace;
}

list<int>::iterator CPlayerCharacter::GetFirstTracePoint()
{
    return this->trace.begin();
}

list<int>::iterator CPlayerCharacter::GetLastTracePoint()
{
    return this->trace.end();
}
