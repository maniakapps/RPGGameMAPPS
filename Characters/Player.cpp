//
// Created by ap on 20/07/21.
//

#include "Player.h"

Player::Player(string n, int h , int a, int d): GameCharacter(n, h, a, d) {
    Item dagger = Item("Dagger", 0, 5, 0);
    addItem(dagger);
}

void Player::addItem(Item item) {
    inventory.push_back(item);
    increaseStats(item.health, item.attack, item.defence);
}

void Player::increaseStats(int h, int a, int d) {
    currentHealth += h;
    maxHealth += h;
    attack += a;
    defence += d;
}

void Player::lootRoom(Room *room) {
    vector<Item> items = room->items;
    for (auto & item : items){
        addItem(item);
    }
}

void Player::changeRoom(Room *newRoom) {
    previousRoom = currentRoom;
    currentRoom = newRoom;
}
