#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

// #include <QMediaPlayer>
// #include <QAudioOutput>


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
            /* Correct code yet missing Qt files
            QMediaPlayer *sound= new QMediaPlayer();
            QAudioOutput *volume= new QAudioOutput();
            sound->setSource(OUrl ("qrc:/resource/Dead Chicken.mp3"));
            sound->setAudioOutput (volume);
            voulume->setVolume(10000);
            sound->play();

    */
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
