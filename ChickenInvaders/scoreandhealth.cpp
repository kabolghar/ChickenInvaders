#include "scoreandhealth.h"

ScoreandHealth::ScoreandHealth(), QGraphicsTextItem(){

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}
