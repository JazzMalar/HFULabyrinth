#pragma once
#ifndef __ICHARACTER__H
#define __ICHARACTER__H

#include "LabyrinthController.h"
#include "IItem.h"
#include <list>
#include <QBrush>

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
    QBrush* brush;
    int steps;


public:
    virtual bool Move(Direction dir) = 0;
    virtual int GetPosition() = 0;
    virtual QBrush* GetBrush() = 0;
    virtual int GetSteps() = 0;

    virtual list<int>* GetTraceLine() = 0;
    virtual list<int>::iterator GetFirstTracePoint() = 0;
    virtual list<int>::iterator GetLastTracePoint() = 0;

    ICharacter();
	~ICharacter();



};

#endif
