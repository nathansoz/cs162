#include "SozLibs/Dice.h"

#include "GameChars/Character.h"
#include "GameChars/Barbarian.h"
#include "GameChars/BlueMen.h"
#include "GameChars/Goblin.h"
#include "GameChars/ReptilePeople.h"
#include "GameChars/Shadow.h"

#include <iostream>
#include <stack>
#include <queue>

void AddChars(std::queue<Character*> *charQueue, int numPlayers)
{
    int playerCount = numPlayers;

    do
    {
        int playerSelection = -1;
        int numOfType = -1;

        std::cout << "Please select the character type that you would like to add" << std::endl;
        std::cout << "1. Barbarian" << std::endl;
        std::cout << "2. BlueMen" << std::endl;
        std::cout << "3. Goblin" << std::endl;
        std::cout << "4. ReptilePeople" << std::endl;
        std::cout << "5. ShadowMen" << std::endl;
        std::cout << std::endl << "Selection: ";
        std::cin >> playerSelection;

        if(playerSelection > 0 && playerSelection < 6)
        {
            do
            {
                std::cout << "How many of this type should we add? (Max: " << playerCount << ")" << ": ";
                std::cin >> numOfType;
            } while(numOfType < 1 && numOfType <= playerCount);

            playerCount -= numOfType;

            switch(playerSelection)
            {
                case(1):
                    for(int i = 0; i < numOfType; i++)
                    {
                        charQueue->push(new Barbarian());
                    }
                    break;
                case(2):
                    for(int i = 0; i < numOfType; i++)
                    {
                        charQueue->push(new BlueMen());
                    }
                    break;
                case(3):
                    for(int i = 0; i < numOfType; i++)
                    {
                        charQueue->push(new Goblin());
                    }
                    break;
                case(4):
                    for(int i = 0; i < numOfType; i++)
                    {
                        charQueue->push(new ReptilePeople());
                    }
                    break;
                case(5):
                    for(int i = 0; i < numOfType; i++)
                    {
                        charQueue->push(new Shadow());
                    }
                    break;
                default:
                    break;

            }


        }
    }
    while(playerCount > 0);

}

int GetNumberOfSimulations()
{
    int numSims = -1;

    while(true)
    {
        std::cout << "Please enter the number of characters that each player will be allowed to have: ";
        std::cin >> numSims;

        if (numSims <= -1)
        {
            std::cout << "Invalid entry, please try again." << std::endl;
        }
        else
        {
            return numSims;
        }
    }
}

int main()
{
    int numSims;

    //Define containers needed for our simulation
    std::queue<Character*> *player1Challengers = new std::queue<Character*>();
    std::queue<Character*> *player2Challengers = new std::queue<Character*>();
    std::stack<Character> *player1Defeated = new std::stack<Character>();
    std::stack<Character> *player2Defeated = new std::stack<Character>();

    numSims = GetNumberOfSimulations();

    AddChars(player1Challengers, numSims);
    AddChars(player2Challengers, numSims);

    return 0;
}