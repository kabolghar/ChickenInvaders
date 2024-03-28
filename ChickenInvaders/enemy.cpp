#include "enemy.h"
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int

extern Game *game;

#include <QDebug>
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);


    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);
    if (y() +75 < 0){
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            game->s->increase();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }

    }

}


