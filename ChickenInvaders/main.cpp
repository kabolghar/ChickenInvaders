#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Player * player = new Player();
    player->setPixmap(QPixmap(":/resource/ship.png").scaled(50,100));


    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-100);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
