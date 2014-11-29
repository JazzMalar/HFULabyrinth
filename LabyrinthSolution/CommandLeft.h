#pragma once
#include "CharacterCommand.h"
class CCommandLeft :
	public CCharacterCommand
{
public:
    void execute(CCharacterController& controller, int characterIndex) override;

	CCommandLeft();
~CCommandLeft();
};

