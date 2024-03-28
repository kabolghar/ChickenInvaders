#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "game.h"
#include "scorehealth.h"
#include <QDebug>

extern Game * game;

Bullet::Bullet(): QObject(), QGraphicsPixmapItem(){


    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Bullet::move(){
    // if bullet collides with enemy, destroy both


    // move bullet up
    setPos(x(),y()-10);
    if (y() + 50 < 0){
        scene()->removeItem(this);
        delete this;

    }
}

