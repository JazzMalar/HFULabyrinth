
#include "stdafx.h"
#include "LabyrinthController.h"


CLabyrinthController::CLabyrinthController()
{
	m_pLab = new CLabyrinth(10, 10); 
	m_iCurrentCell = 0; 

    m_pLab->Initialize();
    m_pLab->Build();

}

CLabyrinthController::CLabyrinthController(int width, int height)
{
	m_pLab = new CLabyrinth(width, height); 
	m_iCurrentCell = 0; 

    m_pLab->Initialize();
    m_pLab->Build();
}

void CLabyrinthController::Print()
{
	m_pLab->Print();
}

bool CLabyrinthController::IsCellVisited(int cell)
{
	return m_pLab->GetCell(cell).IsVisited(); 
}

bool CLabyrinthController::IsWallDestroyed(int cell, Direction dir)
{
	return m_pLab->GetWall(cell, dir).IsDestroyed(); 
}

bool CLabyrinthController::IsWallSeeThrough(int cell, Direction dir)
{
	return false;
}

int CLabyrinthController::GetCellCount()
{
    return m_pLab->GetCellCount();
}

int CLabyrinthController::GetFirstCell()
{
	return m_pLab->GetFirstCell(); 
}

int CLabyrinthController::GetWidth()
{
    return m_pLab->GetWidth();
}

int CLabyrinthController::GetHeight()
{
    return m_pLab->GetHeight();
}

int CLabyrinthController::GetLastCell()
{
	return m_pLab->GetLastCell(); 
}

int CLabyrinthController::GetCell(int cell)
{
	int returnValue = m_pLab->GetCell(cell).GetIndex(); 
	
	return returnValue; 
}

int CLabyrinthController::GetNextCell(int cell, Direction dir)
{
	CCell& c = m_pLab->GetCell(cell); 
	IWall& wall = m_pLab->GetWall(cell, dir); 

	int returnValue = c.GetIndex(); 

	if (wall.GetOtherNeighbour(&c) != nullptr)
	{
		returnValue = wall.GetOtherNeighbour(&c)->GetIndex(); 
	}

	m_iCurrentCell = returnValue; 

	return returnValue;
}

int CLabyrinthController::GetNextCell()
{
	return ++m_iCurrentCell;
}


CLabyrinthController::~CLabyrinthController()
{
}
