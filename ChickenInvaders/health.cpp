#include "health.h"
#include "game.h"
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QPushButton>
#include <QFont>
#include <QApplication>
#include <QProcess>


extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {

    health = 3;
    setFont(QFont(" ", 16));
    setDefaultTextColor(Qt::white);
    setPlainText("Health: " + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health));
    if (health==0){
        QMessageBox *Q = new QMessageBox;
        Q->setText("Game Over");
        QPushButton *end = Q->addButton(tr("End Game"),QMessageBox::ActionRole);
            Q->exec();
        if (Q->clickedButton()==end){
                game->close();
            }
    }
}

int Health::getHealth()
{
    return health;
}
