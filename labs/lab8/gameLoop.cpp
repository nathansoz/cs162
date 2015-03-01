#include "Maze.h"

#include <iostream>

void GameLoop(Maze* maze)
{
    Room* currentRoom = maze->GetStart();
    bool exit = false;
    bool displayLabels;
    char labels;

    std::cout << std::endl << "Welcome to the maze game! Use command x to E(x)it at any time." << std::endl << std::endl;

    do
    {
        std::cout << "Do you want room labels turned on? (y/n): ";
        labels = std::getchar();
        std::cin.ignore(1000, '\n');

        if(tolower(labels) == 'y')
            displayLabels = true;
        else if(tolower(labels) == 'n')
            displayLabels = false;
        else
            std::cout << "Invalid input, try again." << std::endl << std::endl;

    } while(tolower(labels) != 'y' && tolower(labels) != 'n');

    while(currentRoom != maze->GetEnd() && !exit)
    {
        char command;

        if(displayLabels)
            std::cout << std::endl << "You are in a room with label: '" << currentRoom->GetLabel() << "'"<< std::endl;
        else
            std::cout << std::endl << "You are in a room" << std::endl;
        std::cout << "You can go: ";
        if(currentRoom->GetRoom(NORTH) != nullptr)
            std::cout << "(n)orth  ";
        if(currentRoom->GetRoom(EAST) != nullptr)
            std::cout << "(e)ast  ";
        if(currentRoom->GetRoom(SOUTH) != nullptr)
            std::cout << "(s)outh  ";
        if(currentRoom->GetRoom(WEST) != nullptr)
            std::cout << "(w)est  ";
        std::cout << std::endl;

        std::cout << "Please enter your command: ";
        command = std::getchar();
        std::cin.ignore(1000, '\n');

        switch(tolower(command))
        {
            case 'n':
            {
                Room *tmpRoom = currentRoom->GetRoom(NORTH);
                if (tmpRoom == nullptr)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the north." << std::endl;
                    currentRoom = tmpRoom;
                }

                break;
            }
            case 'e':
            {
                Room *tmpRoom = currentRoom->GetRoom(EAST);
                if (tmpRoom == nullptr)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the east." << std::endl;
                    currentRoom = tmpRoom;
                }

                break;
            }
            case 's':
            {
                Room *tmpRoom = currentRoom->GetRoom(SOUTH);
                if (tmpRoom == nullptr)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the south." << std::endl;
                    currentRoom = tmpRoom;
                }

                break;
            }
            case 'w':
            {
                Room *tmpRoom = currentRoom->GetRoom(WEST);
                if (tmpRoom == nullptr)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the west." << std::endl;
                    currentRoom = tmpRoom;
                }

                break;
            }
            case 'x':
            {
                exit = true;
                break;
            }
            default:
            {
                std::cout << "Invalid command!" << std::endl;
            }
        }

    }

    if(exit)
    {
        std::cout << "We hope you come to play again!" << std::endl;
    }
    else
    {
        std::cout << "Congratulations! You made it to the end! Now exiting." << std::endl;
        return;
    }
}


int main()
{
    Maze* gameMaze = new Maze();

    GameLoop(gameMaze);

    //Implemented destructor that takes care of all memory associated with Maze object
    delete gameMaze;

    return 0;
}
