#pragma once

#ifndef IWALL__H
#define IWALL__H

#include "Cell.h"

class IWall
{
protected: 

	CCell *first;
	CCell *second;
	bool isDestroyed;

public:
	IWall();

	virtual CCell* GetOtherNeighbour(CCell*) = 0;
	virtual void SetNeighbour(CCell& cell) = 0;
	virtual bool IsDestroyed() = 0; 
	virtual void Destroy() = 0; 

    virtual ~IWall();
};

#endif
