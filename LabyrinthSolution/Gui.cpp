#include "stdafx.h"
#include "Gui.h"
#include <iostream>

using namespace std; 

CGui::CGui()
{
	int x; 
	int y; 

	PrintWelcomeMessage(); 

	x = PrintWidthQuestion(); 
	y = PrintHeightQuestion(); 


	lab = new CLabyrinthController(x, y); 
	lab->Print();


}


CGui::~CGui()
{
}

void CGui::PrintWelcomeMessage()
{
	cout << "Willkommen zum verrueckten Labyrinth" << endl;
}

void CGui::PrintLabyrinth()
{
	cout << "blablablabal" << endl;
}

int CGui::PrintWidthQuestion()
{
	int i = 0;
	cout << "Gib die Breite des zu generierenden Labyrinths ein." << endl; 
	cin >> i;

	return i;

}

int CGui::PrintHeightQuestion()
{
	int i = 0;
	cout << "Gib die Hoehe des zu generierenden Labyrinths ein." << endl;
	cin >> i; 
	return i; 
}
