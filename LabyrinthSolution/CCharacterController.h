#ifndef CPLAYERCONTROLLER_H
#define CPLAYERCONTROLLER_H

#include "Direction.h"
#include <deque>
#include <QBrush>
#include <list>
#include <stack>
#include <CCommandSet.h>

class CLabyrinthController;
class CPlayerCharacter;

class CCharacterController
{
private:

    std::deque<CPlayerCharacter> characters;
    std::stack<CCommandSet> commandSets;

    bool dirty;

public:
    CCharacterController();

    bool IsDirty();
    int GetCurrentPosition(int characterIndex);
    int GetPlayerCount();
    int GetCommandsLeft();
    void MessUp();
    void MovePlayer(int characterIndex, Direction dir);
    void AddPlayer(CLabyrinthController* lab);
    void AddPlayer(CLabyrinthController* lab, int startPoint, QBrush* brush);
    void AddPlayer(CLabyrinthController* lab, int startPoint, CCommandSet cmds,  QBrush* brush);
    CCommandSet GetCommandSet();
    std::list<int>* GetTraceLine(int characterIndex);
    QBrush* GetBrushOfPlayer(int characterIndex);


};

#endif // CPLAYERCONTROLLER_H
