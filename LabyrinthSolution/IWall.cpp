#include "IWall.h"

IWall::IWall()
{
}


IWall::~IWall()
{
	delete first; 
	delete second;
}
