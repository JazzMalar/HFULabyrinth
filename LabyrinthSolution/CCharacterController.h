#ifndef CPLAYERCONTROLLER_H
#define CPLAYERCONTROLLER_H

#include "Direction.h"
#include <deque>
#include <QBrush>
#include <list>
#include <stack>

class CKeySet;
class CharacterCommand;
class CLabyrinthController;
class CPlayerCharacter;

class CCharacterController
{
private:

    std::deque<CPlayerCharacter> characters;
    std::stack<CKeySet> keySets;

    bool dirty;

public:
    CCharacterController();

    bool IsDirty();
    int GetCurrentPosition(int characterIndex);
    int GetPlayerCount();
    int GetKeySetsLeft();
    void MessUp();
    void MovePlayer(int characterIndex, Direction dir);
    void AddPlayer(CLabyrinthController* lab);
    void AddPlayer(CLabyrinthController* lab, int startPoint, QBrush* brush);
    void AddPlayer(CLabyrinthController* lab, int startPoint, CKeySet cmds,  QBrush* brush);
    CKeySet GetKeySet();
    std::list<int>* GetTraceLine(int characterIndex);
    QBrush* GetBrushOfPlayer(int characterIndex);
    void HandleInput(int key);

};

#endif // CPLAYERCONTROLLER_H
