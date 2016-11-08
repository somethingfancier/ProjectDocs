#ifndef WORLDPLAYER_H
#define WORLDPLAYER_H

#include <worldchar.h>
#include "worlditem.h"
#include "world.h"
#include <vector>
#include <string>
#include <worldscore.h>
#include <worldlives.h>
#include <worldhealth.h>

class WorldPlayer : public WorldCharacter
{
private:
    WorldLives* lives;              //Total lives of a player
    WorldItem* equippedItem;        //Item that the player is using
    vector<WorldItem*> playerItems; //All of the items that a player has collected
    string username;                //Entered name of a Player
    WorldScore* score;
    int onDeadX;
    int onDeadY;
public:
    //Constructor
    WorldPlayer(): username("<Segfault>"),onDeadX(100),onDeadY(100){lives = new WorldLives; equippedItem = new WorldItem(); score = new WorldScore();} //Lives of a player intially set to 3
    ~WorldPlayer(){}

    //Accessors
    string getUserName(){return username;}
    WorldLives* getLives(){return lives;}
    WorldItem* getItem(){return equippedItem;}
    int getDeadLocX(){return onDeadX;}
    int getDeadLocy(){return onDeadY;}

    //Mutators
    void setLives(WorldLives* newLives){lives = newLives;}
    void setScore(WorldScore* newScore){score = newScore;}
    void setItem(WorldItem* newItem){equippedItem = newItem;}
    void setUsername(){username = "<SegFault>";}      //Indiscriminately set the player's name to SegFault
                                                      //(Thus the madness begins)
    void strike(WorldCharacter*);
    bool longAttack();
    void attack(World*);
    void applyItem();
};

#endif // WORLDPLAYER_H
