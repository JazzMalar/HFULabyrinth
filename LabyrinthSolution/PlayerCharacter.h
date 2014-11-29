#pragma once
#ifndef __CPLAYERCHARACTER__H
#define __CPLAYERCHARACTER__H

#include "ICharacter.h"
#include <QBrush>
#include "CCommandSet.h"

class CPlayerCharacter :
	public ICharacter
{

public:
CPlayerCharacter(CLabyrinthController * lab, int startPoint, Direction allowedDirection, QBrush* brush);
CPlayerCharacter(CLabyrinthController* lab, int startPoint, CCommandSet commands, Direction allowedDir, QBrush* b);
~CPlayerCharacter();

// Inherited via ICharacter
virtual bool Move(Direction dir) override;
virtual int GetPosition() override;
virtual QBrush* GetBrush() override;
virtual int GetSteps() override;
virtual list<int>* GetTraceLine() override;
virtual list<int>::iterator GetFirstTracePoint() override;
virtual list<int>::iterator GetLastTracePoint() override;

private:
CCommandSet commandSet;

};

#endif
