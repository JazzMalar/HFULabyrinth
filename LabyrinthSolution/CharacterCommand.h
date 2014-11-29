#pragma once

#include "CCharacterController.h"
#include "Direction.h"


class CCharacterCommand
{
private:

public:
    CCharacterCommand();
    virtual void execute(CCharacterController& controller, int characterIndex) = 0;

protected:
	Direction commandDirection;
	~CCharacterCommand();
};

