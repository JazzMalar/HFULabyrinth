#pragma once
#include "CharacterCommand.h"
class CCommandDown :
	public CCharacterCommand
{
public:
    void execute(CCharacterController& controller, int characterIndex) override;

	CCommandDown();
~CCommandDown();
};

