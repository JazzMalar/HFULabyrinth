#include "Cell.h"

CCell::CCell(IWall& left, IWall& top, IWall& right, IWall& bottom)
{
	wallLeft = &left; 
	wallTop = &top;
	wallRight = &right; 
	wallBottom = &bottom;
	isVisited = false; 
}

CCell::CCell()
{
	isVisited = false; 
}

CCell::CCell(int index)
{
	isVisited = false; 
	this->index = index; 
}

CCell::~CCell()
{

}

int CCell::GetIndex()
{
	return index; 
}

void CCell::SetWallLeft(IWall* wall)
{
	wallLeft = wall;
}

void CCell::SetWallTop(IWall* wall)
{
	wallTop = wall;
}

void CCell::SetWallRight(IWall* wall)
{
	wallRight = wall;
}

void CCell::SetWallBottom(IWall* wall)
{
	wallBottom = wall;
}

IWall* CCell::GetWallLeft()
{
	return wallLeft; 
}
IWall* CCell::GetWallTop()
{
	return wallTop;
}
IWall* CCell::GetWallRight()
{
	return wallRight;
}
IWall* CCell::GetWallBottom()
{
	return wallBottom;
}

void CCell::Visit()
{
	isVisited = true;
}

bool CCell::IsVisited()
{
	return isVisited;
}
