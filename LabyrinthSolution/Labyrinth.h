#pragma once

#ifndef LABYRINTH__H
#define LABYRINTH__H

#include <iostream>
#include <vector>
#include <deque>
#include "IWall.h"
#include "Cell.h"
#include "ConcreteWall.h"
#include <algorithm>
#include "Direction.h"

using namespace std; 

class CLabyrinth
{
private:
	CLabyrinth(); 
	bool isBuilt; 
	
	int labWidth; 
	int labHeight;

	deque<CCell> cells; 
	deque<CConcreteWall> walls; 

//	deque<CCell>::iterator getRandomStartPoint(); 

	void tryVisit(CCell* cell, IWall* wall);

    template<typename Iter, typename RandomGenerator>
    Iter select_randomly(Iter start, Iter end, RandomGenerator& g)
    {
        std::uniform_int_distribution<> dis(0, std::distance(start, end) -1);
        std::advance(start, dis(g));
        return start;
    }

    template<typename Iter>
    Iter select_randomly(Iter start, Iter end)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return select_randomly(start, end, gen);
    }

public:
	CLabyrinth(int x, int y);
	~CLabyrinth();

	void Initialize(); 
	void Build(); 
	void Print(); 

	CCell& GetCell(int cell); 
	IWall& GetWall(int cell, Direction dir); 
	
    int GetCellCount();
	int GetFirstCell(); 
	int GetLastCell(); 
	int GetWidth(); 
	int GetHeight(); 

	friend ostream& operator<<(ostream& o, const CLabyrinth&);



};

#endif
