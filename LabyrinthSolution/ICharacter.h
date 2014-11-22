#pragma once
#ifndef __ICHARACTER__H
#define __ICHARACTER__H

#include "Direction.h"
#include "IItem.h"
class ICharacter
{
private:
	int position;
	int fieldsMoved; 
	int maxHealth;
	int maxDamage;

	IItem* itemInPosession; 

public:
	virtual void Move(Direction dir) = 0; 
	ICharacter();
	~ICharacter();
};

#endif