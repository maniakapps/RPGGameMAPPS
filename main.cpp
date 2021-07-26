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
    GameCharacter initialBoss = GameCharacter("Mountruo fuerte inicial", 140, 100, 80);
    vector<GameCharacter> fifthRoomEnemies;
    fifthRoomEnemies.push_back(initialBoss);
    Room fifthRoom = Room(4, false, vector<Item>(), fifthRoomEnemies);

    // sixth room
    GameCharacter finalBoss = GameCharacter("Jefe final", 4000, 150, 200);
    vector<GameCharacter> sixthRoomEnemies;
    fifthRoomEnemies.push_back(finalBoss);
    Room sixthRoom = Room(5, true, vector<Item>(), fifthRoomEnemies);

    // Dungeons
    Dungeon dungeon = Dungeon(player, 1);
    dungeon.rooms[0] = firstRoom;
    dungeon.rooms[1] = secondRoom;
    dungeon.rooms[2] = thirdRoom;
    dungeon.rooms[3] = fourthRoom;
    dungeon.rooms[4] = fifthRoom;
    dungeon.rooms[5] = sixthRoom;

    Dungeon dungeon2 = Dungeon(player, 2);
    dungeon2.rooms[0] = firstRoom;
    dungeon2.rooms[1] = secondRoom;
    dungeon2.rooms[2] = thirdRoom;
    dungeon2.rooms[3] = fourthRoom;
    dungeon2.rooms[4] = fifthRoom;
    dungeon2.rooms[5] = sixthRoom;

    while (true) {
        cout << "Elije una Dungeon 1, 2 o 3 para salir: ";
        int dungSelection, result;
        cin >> dungSelection;
        if (dungSelection==1){
        result = dungeon.runDungeon();
        if (result == 0){
            cout << "Adios!";
            break;
        }
        }else if(dungSelection==2) {
            result = dungeon2.runDungeon();
            if (result == 0){
                cout << "Adios!";
                break;
            }
        }else{
            cout << "Adios!";
            break;
        }
    }
}
