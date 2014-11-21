#include "LabyrinthController.h"
#pragma once

class CGui
{
private:
	CLabyrinthController* lab; 
	void PrintWelcomeMessage(); 
	void PrintLabyrinth(); 

	int PrintWidthQuestion();
	int PrintHeightQuestion(); 

public:
	CGui();
	~CGui();
};

