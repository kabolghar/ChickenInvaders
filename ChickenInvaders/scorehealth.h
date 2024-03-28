#ifndef SCOREHEALTH_H
#define SCOREHEALTH_H

#include <QGraphicsTextItem>

class ScoreHealth: public QGraphicsTextItem
{
public:
    ScoreHealth();
    void decrease();
    void increase();
    int getScore();
    int getHealth();
private:
    int score = 0;
    int health = 3;
};

#endif // SCOREHEALTH_H
