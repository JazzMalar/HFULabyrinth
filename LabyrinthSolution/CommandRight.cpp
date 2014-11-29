#include "CommandRight.h"


CCommandRight::CCommandRight()
{
	this->commandDirection = Direction::Right;
}


CCommandRight::~CCommandRight()
{
}

void CCommandRight::execute(CCharacterController& controller, int characterIndex)
{
    controller.MovePlayer(characterIndex, Direction::Right);
}
