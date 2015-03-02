#include "SozLibs/Dice.h"

#include "GameChars/Character.h"
#include "GameChars/Barbarian.h"
#include "GameChars/BlueMen.h"
#include "GameChars/Goblin.h"
#include "GameChars/ReptilePeople.h"
#include "GameChars/Shadow.h"

#include <iostream>
#include <stack>
#include <vector>
#include <queue>


void AddChars(std::queue<Character*> *charQueue, int numPlayers)
{
    int playerCount = numPlayers;

    do
    {
        int playerSelection = -1;
        std::string displayName = "";


        std::cout << std::endl << "Please select the character type that you would like to add ("
                  << playerCount << " characters remaining):" << std::endl;
        std::cout << "1. Barbarian" << std::endl;
        std::cout << "2. BlueMen" << std::endl;
        std::cout << "3. Goblin" << std::endl;
        std::cout << "4. ReptilePeople" << std::endl;
        std::cout << "5. ShadowMen" << std::endl;
        std::cout << std::endl << "Selection: ";
        std::cin >> playerSelection;

        if(playerSelection > 0 && playerSelection < 6)
        {
            std::cin.ignore(1000, '\n');
            std::cout << "What should the name of this character be: ";
            do
            {
                getline(std::cin, displayName);
            } while(displayName == "");



            switch(playerSelection)
            {
                case(1):
                    charQueue->push(new Barbarian(displayName));
                    break;
                case(2):
                    charQueue->push(new BlueMen(displayName));
                    break;
                case(3):
                    charQueue->push(new Goblin(displayName));
                    break;
                case(4):
                    charQueue->push(new ReptilePeople(displayName));
                    break;
                case(5):
                    charQueue->push(new Shadow(displayName));
                    break;
                default:
                    break;
            }

            playerCount--;
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
            std::stack<Character*> *player1Defeated, std::stack<Character*> *player2Defeated,
            int &player1Kills, int &player2Kills)
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
            tmpChar->AddKill();
            tmpChar->Regen();
            player1Challengers->pop();
            player1Challengers->push(tmpChar);

            //And credit player 1 with the victory
            player1Kills++;

        }
        else if(player2Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player1Defeated->push(player1Challengers->front());
            player1Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player2Challengers->front();
            tmpChar->AddKill();
            tmpChar->Regen();
            player2Challengers->pop();
            player2Challengers->push(tmpChar);

            //And credit player 2 with the victory
            player2Kills++;

        }

        std::cout << "Player 1 has " << player1Challengers->size() << " remaining chars." << std::endl;
        std::cout << "Player 2 has " << player2Challengers->size() << " remaining chars." << std::endl;

        if(player1Challengers->size() == 0 || player2Challengers->size() == 0)
        {
            break;
        }

        //run the whole thing again in reverse to be fair.... I'm sure there is some clever recursive
        //algo that could do this, but this works for now.

        AttackSim(player2Challengers->front(), player1Challengers->front());

        if(player1Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player2Defeated->push(player2Challengers->front());
            player2Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player1Challengers->front();
            tmpChar->AddKill();
            tmpChar->Regen();
            player1Challengers->pop();
            player1Challengers->push(tmpChar);

            //And credit player 1 with the victory
            player1Kills++;
        }
        else if(player2Challengers->front()->IsAlive())
        {
            //Let's get rid of the looser
            player1Defeated->push(player1Challengers->front());
            player1Challengers->pop();

            //And give the winner a break
            Character* tmpChar = player2Challengers->front();
            tmpChar->AddKill();
            tmpChar->Regen();
            player2Challengers->pop();
            player2Challengers->push(tmpChar);

            //And credit player 2 with the victory
            player2Kills++;
        }

        std::cout << "Player 1 has " << player1Challengers->size() << " remaining chars." << std::endl;
        std::cout << "Player 2 has " << player2Challengers->size() << " remaining chars." << std::endl;

    }

}

void DisplayPlaces(std::queue<Character*> *player1Challengers, std::queue<Character*> *player2Challengers,
        std::stack<Character*> *player1Defeated, std::stack<Character*> *player2Defeated)
{
    int currentPlace = 1;
    int currentScore;

    std::priority_queue<Character*, std::vector<Character*>, CompareCharacterKills>* places =
            new std::priority_queue<Character*, std::vector<Character*>, CompareCharacterKills>();

    int numplayer1Chal = player1Challengers->size();
    int numplayer2Chal = player2Challengers->size();
    int numplayer1def = player1Defeated->size();
    int numplayer2def = player2Defeated->size();

    for(int i = 0; i < numplayer1Chal; i++)
    {
        places->push(player1Challengers->front());
        player1Challengers->pop();
    }
    for(int i = 0; i < numplayer2Chal; i++)
    {
        places->push(player2Challengers->front());
        player2Challengers->pop();
    }
    for(int i = 0; i < numplayer1def; i++)
    {
        places->push(player1Defeated->top());
        player1Defeated->pop();
    }
    for(int i = 0; i < numplayer2def; i++)
    {
        places->push(player2Defeated->top());
        player2Defeated->pop();
    }




    while(currentPlace <= 3 && places->size() > 0)
    {
        Character* tmpChar = places->top();
        currentScore = tmpChar->GetKills();
        std::cout << "In " << currentPlace << " with " << tmpChar->GetKills() << " kill(s) is "
                  << places->top()->GetDisplayName() << std::endl;
        places->pop();
        delete tmpChar;

        std::cout << "Also tied:" << std::endl;

        while(places->top()->GetKills() == currentScore && places->size() > 0)
        {
            Character* loopTmpChar = places->top();
            std::cout << loopTmpChar->GetDisplayName() << std::endl;
            places->pop();
            delete loopTmpChar;
        }

        currentPlace++;
    }

    while(places->size() > 0)
    {
        Character* tmpChar = places->top();
        places->pop();
        delete tmpChar;
    }

    delete places;

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
    int player1Kills = 0;
    int player2Kills = 0;

    //Define containers needed for our simulation
    std::queue<Character*> *player1Challengers = new std::queue<Character*>();
    std::queue<Character*> *player2Challengers = new std::queue<Character*>();
    std::stack<Character*> *player1Defeated = new std::stack<Character*>();
    std::stack<Character*> *player2Defeated = new std::stack<Character*>();

    numSims = GetNumberOfSimulations();

    std::cout << std::endl << "Adding characters for player 1: " << std::endl << std::endl;
    AddChars(player1Challengers, numSims);
    std::cout << std::endl << "Adding characters for player 2: " << std::endl << std::endl;
    AddChars(player2Challengers, numSims);

    Battle(player1Challengers, player2Challengers, player1Defeated, player2Defeated, player1Kills, player2Kills);

    DisplayPlaces(player1Challengers, player2Challengers, player1Defeated, player2Defeated);

    std::cout << std::endl << "Player 1 had " << player1Kills << " kills" << std::endl;
    std::cout << "Player 2 had " << player2Kills << " kills" << std::endl;
    if(player1Kills > player2Kills)
        std::cout << "Player 1 wins!" << std::endl;
    else if(player1Kills < player2Kills)
        std::cout << "Player 2 wins!" << std::endl;
    else
        std::cout << "It's a tie!" << std::endl;


    delete player1Challengers;
    delete player2Challengers;
    delete player1Defeated;
    delete player2Defeated;

    return 0;
}