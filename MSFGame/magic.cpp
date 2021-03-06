#include "magic.h"
#include <QTimer>
#include <typeinfo>
#include <QGraphicsScene>
#include "enemy.h"
#include "boss.h"
#include "player.h"
#include <iostream>



Magic::Magic(){
    setPixmap(QPixmap(":/images/images/fire1.png").scaled(30, 30));
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->setInterval(50);
    timer->start();
}

void Magic::move(){

    if (getDirection() == 1) {  //Up
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i<n; ++i) {
            if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
                Enemy* curEnemy = dynamic_cast<Enemy*>(colliding_items.at(i));
                if(curEnemy != NULL)
                {
                    curEnemy->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;

            } else if (typeid(*(colliding_items[i])) == typeid(Boss)) {
                Boss* curBoss = dynamic_cast<Boss*>(colliding_items.at(i));
                if(curBoss != NULL)
                {
                    curBoss->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;

            } else if (colliding_items[i] && typeid(*(colliding_items[i]))!= typeid(Player) && typeid(*(colliding_items[i]))!= typeid(Magic)) {
                scene()->removeItem(this);
                delete this;
                return;
            }
         }
        setPos(x(),y()-8);
        string str = string(":/images/images/fire") + to_string(anim) + ".png";
        const char * c = str.c_str();
        setPixmap(QPixmap(c).scaled(30,30));
        if (anim == 15) {
            anim = 1;
            setPixmap(QPixmap(":/images/images/fire1.png").scaled(30,30));
        } else {
            anim++;
        }


    } else if (getDirection() == 2) { //Right
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i<n; ++i) {
            if (typeid(*(colliding_items[i])) == typeid(Enemy)) {

                Enemy* curEnemy = dynamic_cast<Enemy*>(colliding_items.at(i));
                if(curEnemy != NULL)
                {
                    curEnemy->getEnemy()->hit(1);
                }

                scene()->removeItem(this);
                delete this;
                return;
            } else if (typeid(*(colliding_items[i])) == typeid(Boss)) {
                Boss* curBoss = dynamic_cast<Boss*>(colliding_items.at(i));
                if(curBoss != NULL)
                {
                    curBoss->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;

            } else if (colliding_items[i] && typeid(*(colliding_items[i]))!= typeid(Player) && typeid(*(colliding_items[i]))!= typeid(Magic)) {
                scene()->removeItem(this);
                delete this;
                return;
            }
         }
        setPos(x()+8,y());
        string str = string(":/images/images/fire") + to_string(anim) + ".png";
        const char * c = str.c_str();
        setPixmap(QPixmap(c).scaled(30,30));
        if (anim == 15) {
            anim = 1;
            setPixmap(QPixmap(":/images/images/fire1.png").scaled(30,30));
        } else {
            anim++;
        }


    } else if (getDirection() == 3) { //Down
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i<n; ++i) {
            if (typeid(*(colliding_items[i])) == typeid(Enemy)) {

                Enemy* curEnemy = dynamic_cast<Enemy*>(colliding_items.at(i));
                if(curEnemy != NULL)
                {
                    curEnemy->getEnemy()->hit(1);
                }

                scene()->removeItem(this);
                delete this;
                return;
            } else if (typeid(*(colliding_items[i])) == typeid(Boss)) {
                Boss* curBoss = dynamic_cast<Boss*>(colliding_items.at(i));
                if(curBoss != NULL)
                {
                    curBoss->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;

            } else if (colliding_items[i] && typeid(*(colliding_items[i]))!= typeid(Player) && typeid(*(colliding_items[i]))!= typeid(Magic)) {
                scene()->removeItem(this);
                delete this;
                return;
            }
         }
        setPos(x(),y()+8);
        string str = string(":/images/images/fire") + to_string(anim) + ".png";
        const char * c = str.c_str();
        setPixmap(QPixmap(c).scaled(30,30));
        if (anim == 15) {
            anim = 1;
            setPixmap(QPixmap(":/images/images/fire1.png").scaled(30,30));
        } else {
            anim++;
        }


    } else if (getDirection() == 4) { //Left
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i<n; ++i) {
            if (typeid(*(colliding_items[i])) == typeid(Enemy)) {

                Enemy* curEnemy = dynamic_cast<Enemy*>(colliding_items.at(i));
                if(curEnemy != NULL)
                {
                    curEnemy->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;
            } else if (typeid(*(colliding_items[i])) == typeid(Boss)) {
                Boss* curBoss = dynamic_cast<Boss*>(colliding_items.at(i));
                if(curBoss != NULL)
                {
                    curBoss->getEnemy()->hit(1);
                }
                scene()->removeItem(this);
                delete this;
                return;

            } else if (colliding_items[i] && typeid(*(colliding_items[i]))!= typeid(Player) && typeid(*(colliding_items[i]))!= typeid(Magic)) {
                scene()->removeItem(this);
                delete this;
                return;
            }
         }
        setPos(x()-8,y());
        string str = string(":/images/images/fire") + to_string(anim) + ".png";
        const char * c = str.c_str();
        setPixmap(QPixmap(c).scaled(30,30));
        if (anim == 15) {
            anim = 1;
            setPixmap(QPixmap(":/images/images/fire1.png").scaled(30,30));
        } else {
            anim++;
        }


    }

}
