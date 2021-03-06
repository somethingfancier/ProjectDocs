#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include "worldenemy.h"
#include "worldplayer.h"


class Boss: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

    WorldEnemy *enemy;
    WorldPlayer *player;
    QTimer* timer;
    QTimer* timertwo;
    QTimer* timerthree;
    QTimer* attacktimer;
    int numMoves;
    int animation;

public:

    Boss(QGraphicsItem * parent=0);

    //Accesors
    WorldEnemy* getEnemy(){return enemy;}
    WorldPlayer* getPlayer(){return player;}

    //Mutators
    void setEnemy(WorldEnemy* newEnemy){enemy = newEnemy;}
    void setPlayer(WorldPlayer* newPlayer){player = newPlayer;}
    void setTimer(QTimer* newTimer);


    void updatePos(){this->setPos(enemy->getX(),enemy->getY());}

public slots:
    void move();
    void bounceAnimation();
    void deathAnimation();
    void setAttack();
};

#endif // BOSS_H
