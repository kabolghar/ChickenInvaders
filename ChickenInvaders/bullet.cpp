#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

extern Game * game;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem() {


    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet:: move()
{

    QList<QGraphicsItem *> collison = collidingItems();
    for (int i = 0; i<collison.size(); i++){
        if (typeid(*(collison[i])) == typeid (Enemy)){

            game->score->increase();

            scene()->removeItem(collison[i]);
            scene()->removeItem(this);

            delete collison[i];
            delete this;



            return;

        }
    }
    setPos(x(),y()-10);
    if (y() + 10 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
