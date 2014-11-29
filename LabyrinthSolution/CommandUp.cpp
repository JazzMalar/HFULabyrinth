#include "CommandUp.h"


CCommandUp::CCommandUp()
{
	commandDirection = Direction::Top; 
}


CCommandUp::~CCommandUp()
{
}

void CCommandUp::execute(CCharacterController& controller, int characterIndex)
{
    controller.MovePlayer(characterIndex, Direction::Top);
}
