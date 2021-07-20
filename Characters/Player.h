//
// Created by ap on 20/07/21.
//
#include "../Rooms/Room.h"
#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H
class Player: public GameCharacter{
public:
    Room *currentRoom;
    Room *previousRoom;
    vector<Item> inventory;
    explicit Player(string="", int = 0, int = 0, int = 0);
    void addItem(Item);
    void increaseStats(int, int, int);
    void lootRoom(Room *);
    void changeRoom(Room *);
};
#endif //RPGGAME_PLAYER_H
