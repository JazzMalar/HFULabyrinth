#include <stdafx.h>
#include "ICharacter.h"

ICharacter::ICharacter()
{

}

ICharacter::~ICharacter()
{
	delete itemInPosession; 
	delete labyrinth;
}