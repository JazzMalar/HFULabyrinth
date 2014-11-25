#include "stdafx.h"
#include "PlayerCharacter.h"


CPlayerCharacter::CPlayerCharacter(CLabyrinthController* lab, int startPoint, Direction allowedDirection)
{
	this->allowedDirection = allowedDirection;
	this->labyrinth = lab; 
	this->position = startPoint; 
}

CPlayerCharacter::~CPlayerCharacter()
{
}

void CPlayerCharacter::Move(Direction dir)
{
	if (this->allowedDirection != Direction::All && dir != this->allowedDirection)
	{
		return; 
	}

	if (labyrinth->IsWallDestroyed(position, dir))
	{
		trace.push_back(position);
		position = labyrinth->GetNextCell(position, dir); 		
	}

}

