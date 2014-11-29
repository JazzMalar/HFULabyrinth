#pragma once
#include "CharacterCommand.h"
class CCommandRight :
	public CCharacterCommand
{
public:
    void execute(CCharacterController& controller, int characterIndex) override;

	CCommandRight();
~CCommandRight();
};

