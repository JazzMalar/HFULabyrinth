#ifndef ITEMHAMMER_H
#define ITEMHAMMER_H

#include "IItem.h"

class ItemHammer :
        public IItem
{
public:
    ItemHammer();
    ~ItemHammer();

    void Collect() override;
    void Use() override;


};

#endif // ITEMHAMMER_H
