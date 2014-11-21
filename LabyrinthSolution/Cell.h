#pragma once
#ifndef	CELL__H
#define CELL__H

// #include "IWall.h"

class IWall; 

class CCell
{

private:
	IWall *wallLeft; 
	IWall *wallTop;
	IWall *wallRight; 
	IWall *wallBottom; 
	bool isVisited; 
	int index; 

public:
	CCell(); 
	CCell(int index); 
	CCell(IWall& left, IWall& top, IWall& right, IWall& bottom);
	
	void Visit();
	bool IsVisited(); 

	void SetWallLeft(IWall* wall); 
	void SetWallRight(IWall* wall); 
	void SetWallTop(IWall* wall); 
	void SetWallBottom(IWall* wall); 

	IWall* GetWallLeft();
	IWall* GetWallTop();
	IWall* GetWallRight();
	IWall* GetWallBottom();

	int GetIndex(); 

	~CCell();
};

#endif
