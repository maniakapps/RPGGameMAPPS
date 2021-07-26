//
// Created by ap on 20/07/21.
//
#include "Item.h"

Item::Item(string n, int h, int a, int d) {
    name = std::move(n);
    health = h;
    attack = a;
    defence = d;
}
