//
// Created by ap on 20/07/21.
//
#include "../Characters/Player.h"
#ifndef RPGGAME_DUNGEON_H
#define RPGGAME_DUNGEON_H
class Dungeon{
    private:
    int number;
public:
    Player player;
    Room rooms[6];
    explicit Dungeon(Player, int);
    int runDungeon();
    void enterRoom(Room *);
    static void handleEmptyRoom();
    void handleRoomWithChest(Room *);
    void handleRoomWithEnemy(Room *);
    void handleLootActions(Room *);
    void handleFightActions(GameCharacter*);
    void handleMovementActions(Room*);
    static void printActions(int, string[]);
    static int performEndGameLogic();
};
#endif //RPGGAME_DUNGEON_H
