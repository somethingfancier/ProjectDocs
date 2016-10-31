#include "game.h"

#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>



Game::Game(QWidget *parent) {
    
    universe = new Universe();
    universe->createFirstWorld();
    universe->getPlayer()->setCoordinates(100,200);

    player = new Player(); //
    player->setPlayer(universe->getPlayer());
    player->updatePos();
    player->setPixmap(QPixmap(":/images/images/WalkDown1.png").scaled(60,60));
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720);
    setBackgroundBrush(QBrush(QImage(":/images/images/World1.png")));


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);


    scene->addItem(player);

    World* world = universe->getWorld(1);
    for (unsigned i=0; i<world->getCharacters().size(); i++) {
        WorldCharacter* enemyData = world->getCharacters().at(i);
        Enemy* newEnemy = new Enemy();
        WorldEnemy* disEnemy = new WorldEnemy();
        disEnemy = static_cast<WorldEnemy*>(enemyData);
        if (disEnemy) {
            newEnemy->setEnemy(disEnemy);
            newEnemy->setPlayer(player->getPlayer());
            //newEnemy->setTimer(player->getTimer());
            newEnemy->updatePos();
        }
        scene->addItem(newEnemy);
    }


    show();
}
