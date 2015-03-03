#pragma once

#include <stddef.h>
#include <string>
#include <vector>

enum Direction {NORTH, EAST, SOUTH, WEST};


struct Room
{

    friend class Maze;

private:
    Room* north;
    Room* east;
    Room* south;
    Room* west;

    std::string label;


public:
    Room(Room* n, Room* e, Room* s, Room* w, std::string label);
    Room* AddRoom(Direction dir, std::string label);
    Room* GetRoom(Direction dir);

    std::string GetLabel();
};

class Maze
{
public:
    Maze();
    ~Maze();

    Room* GetStart();
    Room* GetEnd();
private:

    Room* start;
    Room* end;
    std::vector<Room*>* rooms;
};