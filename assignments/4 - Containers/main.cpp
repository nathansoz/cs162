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

Character* AttackSim(Character *attacker, Character *defender)
{
    while (attacker->IsAlive() && defender->IsAlive())
    {
        if(attacker->IsAlive())
        {
            attacker->Attack(defender);
        }

        if (defender->IsAlive())
        {
            defender->Attack(attacker);
        }
    }
}

void Battle(std::queue<Character*> *player1Challengers, std::queue<Character*> *player2Challengers,
            std::stack<Character*> *player1Defeated, std::stack<Character*> *player2Defeated)
{
    while(player1Challengers->size() > 0 && player2Challengers->size() > 0)
    {
        AttackSim(player1Challengers->front(), player2Challengers->front());

        if(player1Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player2Defeated->push(player2Challengers->front());
            player2Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player1Challengers->front();
            tmpChar->Regen();
            player1Challengers->pop();
            player1Challengers->push(tmpChar);

        }
        else if(player2Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player1Defeated->push(player1Challengers->front());
            player1Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player2Challengers->front();
            tmpChar->Regen();
            player2Challengers->pop();
            player2Challengers->push(tmpChar);

        }

        std::cout << "Player 1 has " << player1Challengers->size() << " remaining chars." << std::endl;
        std::cout << "Player 2 has " << player2Challengers->size() << " remaining chars." << std::endl;

        if(player1Challengers->size() == 0 || player2Challengers->size() == 0)
        {
            break;
        }

        AttackSim(player2Challengers->front(), player1Challengers->front());

        if(player1Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player2Defeated->push(player2Challengers->front());
            player2Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player1Challengers->front();
            tmpChar->Regen();
            player1Challengers->pop();
            player1Challengers->push(tmpChar);
        }
        else if(player2Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player1Defeated->push(player1Challengers->front());
            player1Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player2Challengers->front();
            tmpChar->Regen();
            player2Challengers->pop();
            player2Challengers->push(tmpChar);
        }

        std::cout << "Player 1 has " << player1Challengers->size() << " remaining chars." << std::endl;
        std::cout << "Player 2 has " << player2Challengers->size() << " remaining chars." << std::endl;

    }

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
    srand(time(NULL));
    int numSims;

    //Define containers needed for our simulation
    std::queue<Character*> *player1Challengers = new std::queue<Character*>();
    std::queue<Character*> *player2Challengers = new std::queue<Character*>();
    std::stack<Character*> *player1Defeated = new std::stack<Character*>();
    std::stack<Character*> *player2Defeated = new std::stack<Character*>();

    numSims = GetNumberOfSimulations();

    AddChars(player1Challengers, numSims);
    AddChars(player2Challengers, numSims);

    Battle(player1Challengers, player2Challengers, player1Defeated, player2Defeated);

    while(player1Defeated->size() > 0)
    {
        Character* del = player1Defeated->top();
        player1Defeated->pop();
        delete del;
    }

    while(player2Defeated->size() > 0)
    {
        Character* del = player2Defeated->top();
        player2Defeated->pop();
        delete del;
    }

    while(player1Challengers->size() > 0)
    {
        Character* del = player1Challengers->front();
        player1Challengers->pop();
        delete del;
    }
    while(player2Challengers->size() > 0)
    {
        Character* del = player2Challengers->front();
        player2Challengers->pop();
        delete del;
    }

    delete player1Challengers;
    delete player2Challengers;
    delete player1Defeated;
    delete player2Defeated;

    return 0;
}