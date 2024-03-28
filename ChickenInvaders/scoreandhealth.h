#ifndef SCOREANDHEALTH_H
#define SCOREANDHEALTH_H

#include <QGraphicsTextItem>


class ScoreandHealth: public QGraphicsTextItem
{
public:
    ScoreandHealth();
    void decrease();
};

#endif // SCOREANDHEALTH_H
