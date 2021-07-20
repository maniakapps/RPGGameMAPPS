//
// Created by ap on 20/07/21.
//

#include "GameCharacter.h"

#include <utility>

GameCharacter::GameCharacter(string n, int h, int a, int d) {
    name = std::move(n);
    maxHealth = h;
    currentHealth = h;
    attack = a;
    defence = d;
}
int GameCharacter::takeDamage(int amount) {
    int damage = amount - defence;
    if(damage < 0){ damage = 0;}
    currentHealth -=  damage;
    return damage;
}

bool GameCharacter::checkIsDead(){
    return currentHealth <= 0;
}
