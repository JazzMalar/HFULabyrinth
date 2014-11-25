#pragma once
#include "ICharacter.h"
class CPlayerCharacter :
	public ICharacter
{
public:
CPlayerCharacter(CLabyrinthController * lab, int startPoint, Direction allowedDirection);
~CPlayerCharacter();

// Inherited via ICharacter
virtual void Move(Direction dir) override;
};

