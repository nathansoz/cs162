#include "Maze.h"

Room::Room(Room *n, Room *e, Room *s, Room *w, std::string label)
{
    this->north = n;
    this->east = e;
    this->south = s;
    this->west = w;
    this->label = label;
}

Room* Room::AddRoom(Direction dir, std::string label)
{
    if(dir == NORTH)
    {
        this->north = new Room(NULL, NULL, this, NULL, label);
        return this->north;
    }
    else if(dir == EAST)
    {
        this->east = new Room(NULL, NULL, NULL, this, label);
        return this->east;
    }
    else if(dir == SOUTH)
    {
        this->south = new Room(this, NULL, NULL, NULL, label);
        return this->south;
    }
    else if(dir == WEST)
    {
        this->west = new Room(NULL, this, NULL, NULL, label);
        return this->west;
    }

}

Room* Room::GetRoom(Direction dir)
{
    switch(dir)
    {
        //break statments not needed, return functions as such

        case NORTH:
            return this->north;
        case SOUTH:
            return this->south;
        case EAST:
            return this->east;
        case WEST:
            return this->west;
        default:
            return NULL;
    }
}

std::string Room::GetLabel()
{
    return this->label;
}

Maze::Maze()
{

    //make a path
    start = new Room(NULL, NULL, NULL, NULL, "START");
    Room* pathRoom1 = start->AddRoom(EAST, "ROOM1");
    Room* pathRoom2 = pathRoom1->AddRoom(NORTH, "ROOM2");
    Room* pathRoom3 = pathRoom2->AddRoom(EAST, "ROOM3");
    Room* pathRoom4 = pathRoom3->AddRoom(EAST, "ROOM4");
    Room* pathRoom5 = pathRoom4->AddRoom(SOUTH, "ROOM5");
    end  = pathRoom5->AddRoom(WEST, "END");

    rooms = new std::vector<Room*> {pathRoom1, pathRoom2, pathRoom3, pathRoom4, pathRoom5};
}

Maze::~Maze()
{
    int roomNum = rooms->size();

    for(int i = 0; i < roomNum; i++)
    {
        Room* tmpRoom = rooms->back();
        rooms->pop_back();
        delete tmpRoom;
    }

    delete start;
    delete end;
    delete rooms;
}

Room* Maze::GetStart()
{
    return start;
}

Room* Maze::GetEnd()
{
    return end;
}