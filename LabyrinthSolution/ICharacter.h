#pragma once
#ifndef __ICHARACTER__H
#define __ICHARACTER__H

#include "Direction.h"
#include "IItem.h"
#include "LabyrinthController.h"
#include <list>

class ICharacter
{
private:
	
protected:
	int position;
	int fieldsMoved; 
	int maxHealth;
	int maxDamage;

	IItem* itemInPosession; 
	CLabyrinthController* labyrinth; 
	Direction allowedDirection;
	list<int> trace; 




public:
	virtual void Move(Direction dir) = 0; 
	ICharacter();
	~ICharacter();
};

#endif