#ifndef WORLD_H
#define WORLD_H

#include "worldenemy.h"
#include "worldchar.h"
#include "worldobstacle.h"
#include "worlditem.h"
#include "worldnpc.h"
#include <string>
#include <vector>

using namespace std;

class World{
private:
    int id;
    int upWId;
    int downWId;
    int leftWId;
    int rightWId;

    string name;
    vector<WorldCharacter*> characters;
    vector<WorldItem*> items;
    vector<WorldObstacle*> obstacles;

public:
    //Constructor
    World(int newId, string imageName):id(newId),name(imageName){}
    World():id(0),name(""){}

    //Accessors
    int getId(){return id;}
    int getUpWId(){return upWId;}
    int getDownWId(){return downWId;}
    int getRightId(){return rightWId;}
    int getLeftWId(){return upWId;}

    string getName(){return name;}
    vector<WorldCharacter*>& getCharacters() { return characters; }
    vector<WorldItem*>& getItems() { return items; }
    vector<WorldObstacle*>& getObstacles() { return obstacles; }

    //Mutators
    void setId(int newId){id = newId;}
    void setUpWId(int newId){upWId = newId;}
    void setDownWId(int newId){downWId = newId;}
    void setRightWId(int newId){rightWId = newId;}
    void setLeftWId(int newId){leftWId = newId;}
    void setName(string newName){name = newName;}

    //Adders for the Vectors
    void addCharacter(WorldCharacter*);
    void addItem(WorldItem*);
    void addObstacle(WorldObstacle*);

};

#endif // WORLD_H
