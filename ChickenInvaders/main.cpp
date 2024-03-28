#include <QApplication>
#include "game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game;
    // create a scene

    return a.exec();
}
