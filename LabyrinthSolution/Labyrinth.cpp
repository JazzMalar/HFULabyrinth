#include "stdafx.h"
#include "Labyrinth.h"
#include "ConcreteWall.h"
#include <random>

CLabyrinth::CLabyrinth(int x, int y)
{
	this->labWidth = x;
	this->labHeight = y;

}


CLabyrinth::~CLabyrinth()
{
}

void CLabyrinth::Initialize()
{
	int colCounter = 1;
	int rowCounter = 1;
	int wallCounter = 0;

	for (int i = 0; i < labWidth * labHeight; i++)
	{
		cells.push_back(CCell(i));
		walls.push_back(CConcreteWall());

		CCell& currentCell = cells.back();

		if (colCounter > labWidth)
		{
			colCounter = 1;
			rowCounter++;
		}

		if (colCounter == 1)
		{
			currentCell.SetWallLeft(&walls.back());
			walls.back().SetNeighbour(cells.back());
			walls.push_back(CConcreteWall());
		}
		else
		{
			currentCell.SetWallLeft(cells[i - 1].GetWallRight());
			cells[i - 1].GetWallRight()->SetNeighbour(cells.back());
		}

		if (rowCounter == 1)
		{
			currentCell.SetWallTop(&walls.back());
			walls.back().SetNeighbour(cells.back());
			walls.push_back(CConcreteWall());
		}
		else
		{
			currentCell.SetWallTop(cells[i - (labWidth)].GetWallBottom());
			cells[i - (labWidth)].GetWallBottom()->SetNeighbour(cells.back());
		}

		walls.back().SetNeighbour(cells.back());
		currentCell.SetWallRight(&walls.back());
		walls.push_back(CConcreteWall());

		walls.back().SetNeighbour(cells.back());
		currentCell.SetWallBottom(&walls.back());

		colCounter++;
	}
	cout << "blah" << endl;
}

void CLabyrinth::Print()
{
	int colCounter = 1;
	int rowCounter = 1;
	int wallCounter = 0;

	for (int i = 0; i < labWidth * labHeight; i++)
	{

		CCell& currentCell = cells.at(i);
		IWall* left = currentCell.GetWallLeft();
		IWall* right = currentCell.GetWallRight();
		IWall* top = currentCell.GetWallTop();
		IWall* bottom = currentCell.GetWallBottom();

		if (colCounter > labWidth)
		{
			colCounter = 1;
			rowCounter++;
			cout << endl;
		}

		if (colCounter == 1)
		{
			if (!left->IsDestroyed())
			{
				cout << "L ";
			}
		}

		if (currentCell.IsVisited())
		{
			if (bottom->IsDestroyed())
			{
				cout << " x ";
			}
			else
			{
				cout << " _ ";
			}
		}
		else
		{
			cout << " . ";

			if (!bottom->IsDestroyed())
			{
				cout << " B ";
			}
		}


		if (!right->IsDestroyed())
		{
			cout << " R ";
		}

		colCounter++;
	}
	cout << endl;
}

CCell & CLabyrinth::GetCell(int cell)
{
	return cells.at(cell);
}

int CLabyrinth::GetFirstCell()
{
	return 0;
}

int CLabyrinth::GetCellCount()
{
	return cells.size();
}

int CLabyrinth::GetLastCell()
{
	return ((GetWidth() * GetHeight()) - 1);
}

int CLabyrinth::GetWidth()
{
	return labWidth;
}

int CLabyrinth::GetHeight()
{
	return labHeight;
}

IWall & CLabyrinth::GetWall(int cell, Direction dir)
{
	switch (dir)
	{
	case Direction::Left:
		return *((cells.at(cell)).GetWallLeft());
	case Direction::Top:
		return *((cells.at(cell)).GetWallTop());
	case Direction::Right:
		return *((cells.at(cell)).GetWallRight());
	case Direction::Bottom:
		return *((cells.at(cell)).GetWallTop());
	default:
		return *((cells.at(cell)).GetWallLeft());
	}
}

void CLabyrinth::Build()
{
	random_device rn;
	mt19937 engine(rn());
	uniform_int_distribution<int> dice(0, (cells.size() - 1));

	int startpoint = dice(engine);
	//    CCell& nextCell = cells.at(startpoint);
	CCell& nextCell = cells.at(2);

	tryVisit(&nextCell, nullptr);
	cout << "built" << endl;
}

void CLabyrinth::tryVisit(CCell* cell, IWall* wall)
{
	if (cell == nullptr)
	{
		return;
	}

	if (cell->IsVisited())
	{
		wall->Destroy();
		return;
	}


	cell->Visit();

	if (wall != nullptr)
	{
		wall->Destroy();
	}

	CCell* nextCell;
	IWall* nextWall = cell->GetWallLeft();

	if (!nextWall->IsDestroyed())
	{
		nextCell = nextWall->GetOtherNeighbour(cell);
		tryVisit(nextCell, nextWall);
	}

	nextWall = cell->GetWallTop();

	if (!nextWall->IsDestroyed())
	{
		nextCell = nextWall->GetOtherNeighbour(cell);
		tryVisit(nextCell, nextWall);
	}

	nextWall = cell->GetWallRight();

	if (!nextWall->IsDestroyed())
	{
		nextCell = nextWall->GetOtherNeighbour(cell);
		tryVisit(nextCell, nextWall);
	}

	nextWall = cell->GetWallBottom();

	if (!nextWall->IsDestroyed())
	{
		nextCell = nextWall->GetOtherNeighbour(cell);
		tryVisit(nextCell, nextWall);
	}





	/*
	deque<IWall*> adjWalls = { cell->GetWallRight(), cell->GetWallBottom(), cell->GetWallLeft(), cell->GetWallTop() };
	CCell* nextCell;

	for (int j = 0; j < 4; j++)
	{
	deque<IWall*>::iterator randomIndex = select_randomly(adjWalls.begin(), adjWalls.end());
	IWall* nextWall = *randomIndex;

	if(!nextWall->IsDestroyed())
	{
	nextCell = nextWall->GetOtherNeighbour(cell);
	tryVisit(nextCell, nextWall);
	}

	adjWalls.erase(randomIndex);
	}
	*/

}
