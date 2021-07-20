//
// Created by ap on 20/07/21.
//
#include <string>
#ifndef RPGGAME_ITEM_H
#define RPGGAME_ITEM_H

using namespace std;

class Item{
public:
    string name;
    int health, attack, defence;
    Item(string, int, int, int);
};
#endif //RPGGAME_ITEM_H
