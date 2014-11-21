#pragma once

#ifndef CONCRETE__WALL__H
#define CONCRETE__WALL__H

#include "IWall.h"

class CConcreteWall :
	public IWall
{
public:
	CConcreteWall();
	~CConcreteWall();

	bool IsDestroyed() override;
	void Destroy() override;
	void SetNeighbour(CCell& cell) override;

	// Inherited via IWall
	virtual CCell* GetOtherNeighbour(CCell *) override;

};

#endif