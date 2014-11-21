#include "stdafx.h"
#include "ConcreteWall.h"


CConcreteWall::CConcreteWall()
{
	isDestroyed = false;
	first = nullptr;
	second = nullptr;
}


CConcreteWall::~CConcreteWall()
{
}

bool CConcreteWall::IsDestroyed()
{
	return isDestroyed;
}

void CConcreteWall::Destroy()
{
	isDestroyed = true;
}

void CConcreteWall::SetNeighbour(CCell& cell)
{
	if (first)
	{
		second = &cell;
	}
	else
	{
		first = &cell;
	}
}

CCell* CConcreteWall::GetOtherNeighbour(CCell* cell)
{
	CCell* retValue = cell; 

	if (first == cell)
	{
		retValue = second; 
	}

	if (second == cell)
	{
		retValue = first;
	}

	return retValue;
}
