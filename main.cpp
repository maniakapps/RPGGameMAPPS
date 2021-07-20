#include <iostream>
#include "Dungeons/Dungeon.h"
#include "Characters/Player.h"
#include "Characters/GameCharacter.h"
#include "Items/Item.h"
#include "Rooms/Room.h"

using namespace std;
int main() {
    cout << "¡Bienvenido a Maniakapps RPG! \nIntroduce el nombre de tu jugador: ";
    string playerName;
    cin >> playerName;
    Player player = Player(playerName, 100, 20, 10);

    // Iniciando la primera hanitación.
    Room firstRoom = Room(0, false, vector<Item>(), vector<GameCharacter>());

    // La segunda habitación
    Item sword = Item("Espada", 0, 20, 0);
    Item casco = Item("Casco", 0, 0, 10);
    vector<Item> secondRoomItems;
    secondRoomItems.push_back(sword);
    secondRoomItems.push_back(casco);
    Room secondRoom = Room(1, false, secondRoomItems, vector<GameCharacter>());

    // tercera habitación
    GameCharacter firstEnemy =  GameCharacter("Zombie", 50, 15, 5);
    vector<GameCharacter> thirdRoomEnemies;
    thirdRoomEnemies.push_back(firstEnemy);
    Room thirdRoom =  Room(2, false, vector<Item>(), thirdRoomEnemies);

    // fourth room
    GameCharacter secondEnemy = GameCharacter("Gran zombie", 100, 20, 10);
    vector<GameCharacter> fourthRoomEnemies;
    thirdRoomEnemies.push_back(secondEnemy);
    Room fourthRoom = Room(3, false, vector<Item>(), fourthRoomEnemies);

    // Quinto room
    GameCharacter finalBoss = GameCharacter("Jefe final", 4000, 150, 200);
    vector<GameCharacter> fifthRoomEnemies;
    fifthRoomEnemies.push_back(finalBoss);
    Room fifthRoom = Room(4, false, vector<Item>(), fifthRoomEnemies);

    Dungeon dungeon = Dungeon(player);
    dungeon.rooms[0] = firstRoom;
    dungeon.rooms[1] = secondRoom;
    dungeon.rooms[2] = thirdRoom;
    dungeon.rooms[3] = fourthRoom;
    dungeon.rooms[4] = fifthRoom;

    while (true) {
        int result = dungeon.runDungeon();
        if (result == 0){
            break;
        }
    }
    cout << "Adios!";
}
