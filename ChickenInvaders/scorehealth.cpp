#include "scorehealth.h"
#include "QtGui/qfont.h"

ScoreHealth::ScoreHealth() {

    this->setFont(QFont(" ",16));
    this->setDefaultTextColor(Qt::white);
    this->setPlainText("Score: "+QString::number(getScore()) + '\n' + "Health: " + QString::number(getHealth()));
    this->setPos(10,10);

}

void ScoreHealth::decrease(){
    this->setPlainText("Score: "+QString::number(score) + '\n' + "Health: " + QString::number(health-1));
    health -= health;
}

void ScoreHealth::increase(){

    score++;
    this->setPlainText("Score: "+QString::number(score) + '\n' + "Health: " + QString::number(health));

}

int ScoreHealth::getHealth(){
    return health;
}

int ScoreHealth::getScore(){
    return score;
}
