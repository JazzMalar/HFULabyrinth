#ifndef CCOMMANDSET_H
#define CCOMMANDSET_H

#include <QWidget>
#include "CommandDown.h"
#include "CommandUp.h"
#include "CommandLeft.h"
#include "CommandRight.h"

class CCharacterCommand;

class CKeySet
{
public:
    CKeySet();
    CKeySet(Qt::Key Up, Qt::Key Down, Qt::Key Left, Qt::Key Right) :
        up (Up), down (Down), left (Left), right (Right) { }

    CCharacterCommand* Handle(int key);

private:
    Qt::Key up;
    Qt::Key down;
    Qt::Key left;
    Qt::Key right;
};

#endif // CCOMMANDSET_H
