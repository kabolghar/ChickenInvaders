#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"

#include <QDebug>
void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        QPixmap bul = QPixmap(":/resource/red_laser.png").scaled(10,50);
        bullet->setPixmap(bul);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    QPixmap enem = QPixmap(":/resource/Chicken Inv.png").scaled(50,50);
    enemy->setPixmap(enem);
    scene()->addItem(enemy);
}
