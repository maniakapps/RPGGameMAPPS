//
// Created by ap on 20/07/21.
//

#include "Room.h"

#include <utility>

Room::Room(int p, bool ie, vector<Item> is, vector<GameCharacter> gcs)
{
    pos = p;
    isExit = ie;
    items = std::move(is);
    enemies = std::move(gcs);
}

void Room::clearEnemies() {
    items.clear();
}

void Room::clearLoot() {
    enemies.clear();
}
