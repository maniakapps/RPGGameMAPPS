//
// Created by ap on 20/07/21.
//
#include <vector>
#include "../Items/Item.h"
#include "../Characters/GameCharacter.h"
#ifndef RPGGAME_ROOM_H
#define RPGGAME_ROOM_H
class Room{
public:
    int pos;
    bool isExit;
    vector<Item> items;
    vector<GameCharacter> enemies;
    Room(int = 0, bool = false, vector<Item> =  vector<Item>(), vector<GameCharacter> = vector<GameCharacter>());
    void clearLoot();
    void clearEnemies();
};
#endif //RPGGAME_ROOM_H
