//
// Created by ap on 20/07/21.
//

#include "Dungeon.h"
#include "../Characters/Player.h"
#include <iostream>
#include <utility>

using namespace std;

Dungeon::Dungeon(Player p) {
    player = std::move(p);
}

void Dungeon::printActions(int numActions, string actions[]) {
    cout << "Selecciona una acción: \n";
    for (int i = 0; i < numActions; ++i) {
        cout << actions[i] << "\n";
    }
}

int Dungeon::runDungeon() {
    cout << "Bienvenido al Dungeon! " << player.name << " adentro encontrarás un tesoro.... pero también enemigos. \nEtra bajo tu propio riesgo\n";
    player.currentRoom = &rooms[0];
    player.previousRoom = &rooms[0];
    while (true){
        enterRoom(player.currentRoom);
        if (player.checkIsDead()){
            cout << "¡Juego terminado! ¿Intentar de nuevo?!\n";
            return performEndGameLogic();
        } else{
            if (player.currentRoom->isExit){
                if(player.currentRoom->enemies.empty()){
                    cout << "¡Ganaste! ¿jugar de nuevo?\n";
                    return performEndGameLogic();
                }
            }
        }
        handleMovementActions(player.currentRoom);
    }
}

void Dungeon::enterRoom(Room *room) {
    if(!room->enemies.empty()){
        handleRoomWithEnemy(room);
    }else if (!room->items.empty()){
        handleRoomWithChest(room);
    } else{
        handleEmptyRoom();
    }
}

void Dungeon::handleEmptyRoom() {
    cout << "Entraste a una habitación vacia.\n";
    string actions[] = {"a. Moverse a otra habitación"};
    while (true){
        printActions(1, actions);
        string input;
        cin >> input;
        if (input == "a"){
            return;
        } else{
            cout << "Opción incorrecta\n";
        }
    }
}

void Dungeon::handleRoomWithChest(Room * room) {
    cout << "Entraste en una habitación donde hay un cofre en medio de la misma.\n";
    string actions[] = {"a. Abrir el cofre.", "b. Moverse a otra habitación."};
    while (true){
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a"){
            handleLootActions(room);
            return;
        } else if(input == "b"){
            return;
        } else{
            cout << "Opción incorrecta.\n";
        }
    }
}

void Dungeon::handleRoomWithEnemy(Room *room) {
    GameCharacter enemy = room->enemies.front();
    cout << "Entraste a la habitación y ves un " << enemy.name << ".\n";
    string actions[] ={
            "a. Enfrentar a " + enemy.name,
            "b. Volver a la habitación anterior."
    };
    while (true){
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a"){
            handleFightActions(&enemy);
            return;
        }else if (input == "b"){
            player.changeRoom(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        } else{
            cout << "Opción incorrecta.\n";
        }
    }
}

void Dungeon::handleLootActions(Room *room){
    player.lootRoom(room);
    for (auto & item : room->items) {
        cout << "Abriste un cofre y encontraste: " << item.name<<"\n";
        cout << "Ahora tus estadisticas son: \nSalud:  \n" << player.currentHealth
        <<"\nataque: " << player.attack << "\ndefensa: \n" << player.defence;
    }
    room->clearLoot();
}



int Dungeon::performEndGameLogic() {
    string actions[] = {
            "a. Si",
            "b. No"
    };
    while (true){
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a"){
            return 1;
        } else if(input == "b"){
            return 0;
        } else{
            cout << "Opción incorrecta.\n";
        }
    }
}

void Dungeon::handleFightActions(GameCharacter* enemy) {
    string actions[] = {
            "a. Atacar",
            "b. Escapar"
    };
    while (true){
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a"){
            int damage = enemy-> takeDamage(player.attack);
            cout << "Tus ataques inflingieron " << damage << " de daño.\n";
        }else if (input == "b"){
            player.changeRoom(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        } else{
            cout << "Opción incorrecta \n";
            continue;
        }
        // check if enemy is dead
        if (enemy->checkIsDead()){
            cout << "Haz ganado! derrotaste al monstruo " << enemy->name << ".\n";
            player.increaseStats(10, 5, 5);
            player.currentRoom->clearEnemies();
            return;
        }
        // handle enemy actions
        int damage = player.takeDamage(enemy->attack);
        cout << enemy->name << " inflingio " << damage << "de daño.\n";
        cout << "Ahora tienes" << player.currentHealth << " puntos de vida.\n";
        if (player.checkIsDead()){
            return;
        }
    }
}

void Dungeon::handleMovementActions(Room *room) {
    while (true){
        if (room->pos == 0){
            string actions[] = {
                    "a. Moverce a la derecha",
                    "b. Mover hacia abajo"
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a"){
                player.changeRoom(&rooms[1]);
                return;
            }else if(input == "b"){
                player.changeRoom(&rooms[2]);
                return;
            } else{
                cout << "Opcion incorrecta.\n";
            }
        }else if (room->pos == 1){
            string actions[] = {
                    "a. Moverce a la izquierda",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a"){
                player.changeRoom(&rooms[0]);
                return;
            } else{
                cout << "Opcion incorrecta.\n";
            }
        } else if (room->pos == 2){
            string actions[] = {
                    "a. Moverce hacia arriba",
                    "b. Mover hacia la derecha"
            };
            printActions(2, actions);
            string input;
            cin >>input;
            if (input == "a"){
                player.changeRoom(&rooms[0]);
                return;
            }else if (input == "b"){
                player.changeRoom(&rooms[3]);
                return;
            }else{
                cout << "Opción incorrecta.\n";
            }
        } else{
            string actions[] = {"a. Moverse a la izquierda"};
            printActions(1, actions);
            string input;
            cin >> input;
            if (input=="a"){
                player.changeRoom(&rooms[2]);
                return;
            } else{
                cout << "Opción incorrecta.\n";
            }
        }
    }

}

