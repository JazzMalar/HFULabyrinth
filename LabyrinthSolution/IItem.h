#pragma once
class IItem
{

private:
	int position; 
	int uses; 

public:
	IItem();
	~IItem();

	virtual void Collect() = 0; 
	virtual void Use() = 0; 

};

