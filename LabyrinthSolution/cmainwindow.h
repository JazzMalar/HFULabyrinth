#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QWidget>
#include "LabyrinthController.h"
#include "PlayerCharacter.h"
#include "CCharacterController.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
    void paintEvent(QPaintEvent * event) override;
    void keyPressEvent(QKeyEvent * k) override;
private:
    Ui::CMainWindow *ui;
    CLabyrinthController* m_pLabController;
    CCharacterController* m_pCharacterController;

    bool drawTraceLines;

    QColor randomItemColor();
    void drawLabyrinth();
    void drawWall(QPoint from, QPoint to, IWall* wall, Direction dir);
};

#endif // CMAINWINDOW_H
