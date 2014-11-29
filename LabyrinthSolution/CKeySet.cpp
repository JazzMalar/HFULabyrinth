#include "CKeySet.h"

CKeySet::CKeySet()
{
}


CCharacterCommand* CKeySet::Handle(int key)
{
	if (up == key)
	{
        return new CCommandUp();
	}
	if (down == key)
	{
        return new CCommandDown();
	}
	if (left == key)
	{
        return new CCommandLeft();
	}
	if (right == key)
	{
        return new CCommandRight();
	}

    return nullptr;
}
