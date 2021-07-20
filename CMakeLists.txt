cmake_minimum_required(VERSION 3.16)
project(RPGGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(RPGGame main.cpp Items/Item.cpp Items/Item.h Characters/GameCharacter.cpp Characters/GameCharacter.h Rooms/Room.cpp Rooms/Room.h Characters/Player.cpp Characters/Player.h Dungeons/Dungeon.cpp Dungeons/Dungeon.h)