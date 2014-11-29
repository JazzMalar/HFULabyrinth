#include "CommandLeft.h"


CCommandLeft::CCommandLeft()
{
	this->commandDirection = Direction::Left;
}


CCommandLeft::~CCommandLeft()
{
}

void CCommandLeft::execute(CCharacterController& controller, int characterIndex)
{
    controller.MovePlayer(characterIndex, Direction::Left);
}
