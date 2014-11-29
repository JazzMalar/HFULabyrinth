#include "cmainwindow.h"
#include "ui_cmainwindow.h"
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QKeyEvent>

CMainWindow::CMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    drawTraceLines = false;

    setFocusPolicy(Qt::StrongFocus);

    CMainWindow::m_pLabController = new CLabyrinthController(30,30);
    CMainWindow::m_pCharacterController = new CCharacterController();

    m_pCharacterController->AddPlayer(this->m_pLabController, this->m_pLabController->GetRandomCell(), this->m_pCharacterController->GetKeySet(), new QBrush(randomItemColor(), Qt::SolidPattern) );
}

CMainWindow::~CMainWindow()
{
    delete m_pLabController;
    delete m_pCharacterController;
    delete ui;
}

void CMainWindow::keyPressEvent(QKeyEvent *k)
{
    cout << "Key Event" << endl;
    switch(k->key())
    {
    case Qt::Key_P:
        this->drawTraceLines = !this->drawTraceLines;
        m_pCharacterController->MessUp();
        break;
    case Qt::Key_B:
        if(m_pCharacterController->GetKeySetsLeft() > 0)
        {
            CKeySet cmds = m_pCharacterController->GetKeySet();
            m_pCharacterController->AddPlayer(this->m_pLabController, this->m_pLabController->GetRandomCell(), cmds, new QBrush(randomItemColor(), Qt::SolidPattern) );
            m_pCharacterController->MessUp();
        }
        break;
    default:
        m_pCharacterController->HandleInput(k->key());
        break;
    }
    if(m_pCharacterController->IsDirty())
    {
        update();
    }
}

QColor CMainWindow::randomItemColor()
{
    return QColor::fromHsv(qrand() % 256, 255, 190);
}

void CMainWindow::paintEvent(QPaintEvent *event)
{
    int cellWidth = 30;
    int cellHeight = 30;
    int penWidth = 2;

    Qt::PenStyle style = Qt::PenStyle(1);
    Qt::PenCapStyle cap = Qt::PenCapStyle(1);
    Qt::PenJoinStyle join = Qt::PenJoinStyle(1);

    QPen* pen = new QPen(Qt::blue, penWidth, style, cap, join);
    QBrush* brush = new QBrush(Qt::green, Qt::SolidPattern);

    QPainter painter(this);
    painter.setPen(*pen);
    painter.setBrush(*brush);

    if(m_pLabController->GetHeight()/(float)m_pLabController->GetWidth()>(float)this->height()/this->width())
    {    painter.scale(
                    float(this->height()) / ((m_pLabController->GetHeight() + 2)*cellHeight),
                    float(this->height()) / ((m_pLabController->GetHeight() + 2)*cellHeight));
    }
    else
    {    painter.scale(
                    float(this->width()) / ((m_pLabController->GetWidth() + 2)*cellWidth),
                    float(this->width()) / ((m_pLabController->GetWidth() + 2)*cellWidth));
    }

//    int firstCell = this->m_pLabController->GetFirstCell();

    QPoint first = QPoint(cellWidth*2,cellHeight);
    QPoint second = first;

    int rowCounter = 1;
    int colCounter = 1;

    for(int i = 0; i < this->m_pLabController->GetCellCount(); i++)
    {

        painter.setBrush(*brush);

        if(colCounter == m_pLabController->GetWidth()+1)
        {
            colCounter = 1;
            rowCounter++;
            first.setY(first.y() + cellHeight);
            first.setX(first.x() - cellWidth * m_pLabController->GetWidth());
            second.setY(second.y() + cellHeight);
            second.setX(second.x() - cellWidth * m_pLabController->GetWidth());
        }

        int currentCell = m_pLabController->GetCell(i);


        for(int j = 0; j < m_pCharacterController->GetPlayerCount(); j++)
        {
            int playerPosition = m_pCharacterController->GetCurrentPosition(j);

            QBrush* playerBrush = m_pCharacterController->GetBrushOfPlayer(j);

            if(playerPosition == currentCell)
            {
                painter.setBrush(*playerBrush);
                QPoint player = QPoint(first.x() - (cellWidth /2), first.y() + (cellHeight /2));
                painter.drawEllipse(player, 5, 5);
            }

        }

        second.setX(first.x() - cellWidth);
        if(rowCounter == 1)
        {
            if(!m_pLabController->IsWallDestroyed(currentCell, Direction::Top))
            {
                painter.drawLine(first, second);
            }
        }

        first = second;
        second.setY(first.y() + cellHeight);

        if(colCounter == 1)
        {
            if(!m_pLabController->IsWallDestroyed(currentCell, Direction::Left))
            {
              painter.drawLine(first, second);
            }
        }

        first = second;
        second.setX(first.x() + cellWidth);

        if(!m_pLabController->IsWallDestroyed(currentCell, Direction::Bottom))
        {
          painter.drawLine(first, second);
        }

        first = second;
        second.setY(first.y() - cellHeight);

        if(!m_pLabController->IsWallDestroyed(currentCell, Direction::Right))
        {
          painter.drawLine(first, second);
        }

        second.setX(second.x() + cellWidth);
        first = second;
        colCounter++;


    }

    if(this->drawTraceLines)
    {

        Qt::PenStyle style = Qt::PenStyle(1);
        Qt::PenCapStyle cap = Qt::PenCapStyle(1);
        Qt::PenJoinStyle join = Qt::PenJoinStyle(1);

        for(int i = 0; i < m_pCharacterController->GetPlayerCount(); i++)
        {
            QBrush* traceBrush = m_pCharacterController->GetBrushOfPlayer(i);
            QPen* pen = new QPen(traceBrush->color(), 5, style, cap, join);

            painter.setPen(*pen);

            list<int> trace = *(m_pCharacterController->GetTraceLine(i));

            /*
            int rowTmp = *(trace.begin()) / cellHeight;
            int row = rowTmp + 1;
            int colTmp = *(trace.begin()) - (rowTmp * cellWidth);
            int col = colTmp + 1;
            */

            int rowTmp = *(trace.begin()) / m_pLabController->GetWidth();
            int row = rowTmp + 1;
            int colTmp = *(trace.begin()) - (rowTmp * m_pLabController->GetWidth());
            int col = colTmp + 2;

            QPoint first = QPoint((cellWidth*col) - (cellWidth/2),(cellHeight*row) + (cellHeight/2));
            QPoint second = first;

            for(std::list<int>::iterator it = trace.begin(); it != trace.end(); it++ )
            {
                if(it == trace.begin()) continue;

                /*
                int rowTmp = *(it) / cellHeight;
                int row = rowTmp + 1;
                int colTmp = *(it) - (rowTmp * cellWidth);
                int col = colTmp + 1;
                */
                int rowTmp = *(it) / m_pLabController->GetWidth();
                int row = rowTmp + 1;
                int colTmp = *(it) - (rowTmp * m_pLabController->GetWidth());
                int col = colTmp + 2;
                second = QPoint((cellWidth*col) - (cellWidth/2),(cellHeight*row) + (cellHeight/2));

                painter.drawLine(first, second);

                first = second;
            }
        }
    }


//    if(m_pLabController->)

}
