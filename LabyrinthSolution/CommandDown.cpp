#include "CommandDown.h"


CCommandDown::CCommandDown()
{
	this->commandDirection = Direction::Bottom;
}


CCommandDown::~CCommandDown()
{
}

void CCommandDown::execute(CCharacterController& controller, int characterIndex)
{
    controller.MovePlayer(characterIndex, Direction::Bottom);
}
