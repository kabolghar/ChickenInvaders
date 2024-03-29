#include "score.h"
#include <QGraphicsTextItem>
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {

    score = 0;
    setFont(QFont(" ", 16));
    setDefaultTextColor(Qt::white);
    setPlainText("Score:  " + QString::number(score));
}

void Score::increase()
{
    score += 1;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
