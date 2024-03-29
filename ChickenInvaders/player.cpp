#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QRect>
#include <QDebug>
#include <QKeyEvent>
#include <stdlib.h>

extern Game * game;

Player::Player()
{}

void Player::keyPressEvent(QKeyEvent *event)
{

    if(event->key()== Qt::Key_Left || event->key() == Qt::Key_A)
    {
        if(x()>0)
        {
            collisonPlayer();
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right || event->key() == Qt::Key_D)

    {
        collisonPlayer();
        if(x()+80<800)
            setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Up || event->key() == Qt::Key_W)

    {
        collisonPlayer();
        if(y()>0)
            setPos(x(),y()-10);
    }
    else if(event->key()== Qt::Key_Down || event->key() == Qt::Key_S)

    {
        collisonPlayer();
        if(y()+80<600)
            setPos(x(),y()+10);
    }
    else if(event->key()== Qt::Key_Space)
    {
        QPixmap bul(":/resource/red_laser.png");
        bul = bul.scaled(10,50, Qt::KeepAspectRatio);

        Bullet* bullet = new Bullet;
        bullet->setPixmap(bul);
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);
    }


}

void Player::collisonPlayer()
{
    QList<QGraphicsItem *> collison = collidingItems();
    for (int i = 0; i<collison.size(); i++){
        if (typeid (Enemy) == typeid(*(collison[i]))){
            game->health->decrease();
            scene()->removeItem(collison[i]);
            delete collison[i];
            return;

        }
    }
}

void Player::spawn()
{

    int rn = rand() % 700;
    QPixmap ene(":/resource/chicken.png");
    ene = ene.scaled(50,50, Qt::KeepAspectRatio);
    Enemy* enemy = new Enemy;
    enemy->setPixmap(ene);
    enemy->setPos(rn,0);
    scene()->addItem(enemy);


}
