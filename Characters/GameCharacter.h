//
// Created by ap on 20/07/21.
//
#include <string>
#ifndef RPGGAME_GAMECHARACTER_H
#define RPGGAME_GAMECHARACTER_H
using namespace std;

class GameCharacter{
public:
    string name;
    int maxHealth, currentHealth, attack, defence;
    GameCharacter(string, int , int, int);
    int takeDamage(int);
    bool checkIsDead() const;

    virtual void displayStats();

};
#endif //RPGGAME_GAMECHARACTER_H
