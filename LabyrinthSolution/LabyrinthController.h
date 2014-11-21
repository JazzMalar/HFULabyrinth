#pragma once

#include "Labyrinth.h"
#include "Direction.h"

class CLabyrinthController
{
public:
	CLabyrinthController();
	CLabyrinthController(int width, int height);
	bool IsCellVisited(int cell); 
	bool IsWallDestroyed(int cell, Direction dir);
	bool IsWallSeeThrough(int cell, Direction dir); 

	void Print(); 

	int GetFirstCell(); 
	int GetLastCell(); 
	int GetCell(int cell); 
    int GetCellCount();

    int GetWidth();
    int GetHeight();

	int GetNextCell(int cell, Direction dir); 
	int GetNextCell(); 

	~CLabyrinthController();

private: 
	CLabyrinth* m_pLab; 
	int m_iCurrentCell;

};

