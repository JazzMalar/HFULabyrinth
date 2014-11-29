#ifndef CCOMMANDSET_H
#define CCOMMANDSET_H

#include <QWidget>

class CCommandSet
{
public:
    CCommandSet();
    CCommandSet(Qt::Key Up, Qt::Key Down, Qt::Key Left, Qt::Key Right) :
        up (Up), down (Down), left (Left), right (Right) { }

private:
    Qt::Key up;
    Qt::Key down;
    Qt::Key left;
    Qt::Key right;
};

#endif // CCOMMANDSET_H
