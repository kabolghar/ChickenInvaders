#include "game.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent) {

    scene =  new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setBackgroundBrush(QBrush(QImage(":/resource/backgroun.png").scaled(800,600)));
    setFixedSize(800, 600);
    setScene(scene);

    QPixmap pl(":/resource/ship.png");
    pl = pl.scaled(75, 75, Qt::KeepAspectRatio);

    player = new Player();
    player->setPixmap(pl);
    player->setPos(360, 525);
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score();
    score->setPos(670,10);
    scene->addItem(score);

    health = new Health();
    health->setPos(670,40);
    scene->addItem(health);

    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(spawn()));
    time->start(2000);

    show();
}
