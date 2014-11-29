#pragma once
#ifndef __IITEM__H
#define __IITEM__H

class ICharacter;

class IItem
{

protected:
	int position; 
	int uses; 
    ICharacter* owner;

public:
	IItem();
	~IItem();

	virtual void Collect() = 0; 
	virtual void Use() = 0; 

};

#endif
