#include "worldchar.h"
#include "worldplayer.h"
#include "worldenemy.h"
#include "world.h"
#include <cmath>
#include <iostream>

void WorldPlayer::strike(WorldCharacter* chosenChar)
{
    WorldEnemy* chosenEnemy = static_cast<WorldEnemy*>(chosenChar);
    if(chosenEnemy != NULL)
    {
        chosenEnemy->hit(this->getStrength());

        if(chosenEnemy->isDead())
        {
            score->increase(50);
        }
    }
}

void WorldPlayer::attack(World* world)
{
    for(unsigned int i = 0; i < world->getCharacters().size(); i++)
    {
       WorldEnemy* chosenEnemy = static_cast<WorldEnemy*>(world->getCharacters().at(i));

       if(chosenEnemy != NULL && !(chosenEnemy->isDead()))
       {
           if(this->isBoardering(chosenEnemy) || invincible)
           {
               this->strike(chosenEnemy);
           }
       }
    }
}

void WorldPlayer::applyItem()
{
    if(equippedItem != NULL){
        if(equippedItem->getProperty() == "heart"){
            this->getLives()->increase(1);
        } else if (equippedItem->getProperty() == "health") {
            this->setHealth(getHealth() + 5);
        } else if (equippedItem->getProperty() == "book") {
            this->setBook(true);
        } else if (equippedItem->getProperty() == "key") {
            this->setKey(true);
        }
    }
}
