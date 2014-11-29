#pragma once
#include "CharacterCommand.h"
class CCommandUp :
	public CCharacterCommand
{
public:
    void execute(CCharacterController& controller, int characterIndex) override;

	CCommandUp();
~CCommandUp();
};

