#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#include "Character.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "Goblin.h"
#include "BlueMen.h"
#include "Shadow.h"
#include "SozLibs/Stats.h"

const int NUM_TEST_RUNS = 1000000;

bool sim(Character *char1, Character *char2, int numSims, double margin)
{

    std::vector<int> *char1Results  = new std::vector<int>();
    std::vector<int> *char2Results = new std::vector<int>();

    char1Results->reserve(NUM_TEST_RUNS);
    char2Results->reserve(NUM_TEST_RUNS);

    for(int i = 0; i < numSims; i++)
    {
        while (char1->IsAlive() && char2->IsAlive())
        {
            if(char1->IsAlive())
            {
                char1->Attack(char2);
            }

            if (char2->IsAlive())
            {
                char2->Attack(char1);
            }
        }
        if (char1->IsAlive())
        {
            char1Results->push_back(1);
            char2Results->push_back(0);
        }
        if (char2->IsAlive())
        {
            char1Results->push_back(0);
            char2Results->push_back(1);
        }

        char1->Reset();
        char2->Reset();
    }

    for(int i = 0; i < numSims; i++)
    {
        while (char1->IsAlive() && char2->IsAlive())
        {
            if(char2->IsAlive())
            {
                char2->Attack(char1);
            }

            if (char1->IsAlive())
            {
                char1->Attack(char2);
            }
        }
        if (char1->IsAlive())
        {
            char1Results->push_back(1);
            char2Results->push_back(0);
        }
        if (char2->IsAlive())
        {
            char1Results->push_back(0);
            char2Results->push_back(1);
        }

        char1->Reset();
        char2->Reset();

    }

    double char1Average = SozLibs::Stats::Mean(char1Results);
    double char2Average = SozLibs::Stats::Mean(char2Results);

    std::cout << char1->GetName() << " wins " << char1Average * 100 << " percent of the time." << std::endl;
    std::cout << char2->GetName() << " wins " << char2Average * 100 << " percent of the time." << std::endl;

    delete char1Results;
    delete char2Results;

    if(std::fabs(char1Average - char2Average) <= margin)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void SimulateBarbarianAgainstBarbarian()
{
    bool passed;

    Barbarian *barb1 = new Barbarian();
    Barbarian *barb2 = new Barbarian();
    passed = sim(barb1, barb2,  NUM_TEST_RUNS, .10);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete barb1;
    delete barb2;
}

void SimulateReptilePeopleAgainstReptilePeople()
{

    bool passed;

    ReptilePeople *rep1 = new ReptilePeople();
    ReptilePeople *rep2 = new ReptilePeople();
    passed = sim(rep1, rep2, NUM_TEST_RUNS, .10);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete rep1;
    delete rep2;
}

void SimulateBlueMenAgainstBlueMen()
{

    bool passed;

    BlueMen *blue1 = new BlueMen();
    BlueMen *blue2 = new BlueMen();
    passed = sim(blue1, blue2, NUM_TEST_RUNS, .10);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete blue1;
    delete blue2;
}

void SimulateGoblinAgainstGoblin()
{

    bool passed;

    Goblin *gob1 = new Goblin();
    Goblin *gob2 = new Goblin();
    passed = sim(gob1, gob2, NUM_TEST_RUNS, .10);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete gob1;
    delete gob2;
}

void SimulateShadowAgainstShadow()
{
    bool passed;

    Shadow *shadow1 = new Shadow();
    Shadow *shadow2 = new Shadow();
    passed = sim(shadow1, shadow2, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete shadow1;
    delete shadow2;
};

void SimulateReptilePeopleAgainstBarbarian()
{
    bool passed;

    ReptilePeople *rep = new ReptilePeople();
    Barbarian *barb = new Barbarian();
    passed = sim(rep, barb, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete rep;
    delete barb;
}

void SimulateReptilePeopleAgainstBlueMen()
{
    bool passed;

    ReptilePeople *rep = new ReptilePeople();
    BlueMen *blue = new BlueMen();
    passed = sim(rep, blue, NUM_TEST_RUNS, .80);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete rep;
    delete blue;
}

void SimulateReptilePeopleAgainstGoblins()
{
    bool passed;

    ReptilePeople *rep = new ReptilePeople();
    Goblin *gob = new Goblin();
    passed = sim(rep, gob, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete rep;
    delete gob;
}

void SimulateBarbariansAgainstBlueMen()
{
    bool passed;

    Barbarian *barb = new Barbarian();
    BlueMen *blue = new BlueMen();
    passed = sim(barb, blue, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete barb;
    delete blue;
}

void SimulateBarbariansAgainstGoblins()
{
    bool passed;

    Barbarian *barb = new Barbarian();
    Goblin *gob = new Goblin();
    passed = sim(barb, gob, NUM_TEST_RUNS, 0.4);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete barb;
    delete gob;
}

void SimulateGoblinsAgainstBlueMen()
{
    bool passed;

    Goblin *gob = new Goblin();
    BlueMen *blue = new BlueMen();
    passed = sim(gob, blue, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete gob;
    delete blue;
}

void SimulateShadowAgainstBlueMen()
{
    bool passed;

    Shadow *shadow = new Shadow();
    BlueMen *blue = new BlueMen();
    passed = sim(shadow, blue, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete shadow;
    delete blue;
}

void SimulateShadowAgainstReptilePeople()
{
    bool passed;

    Shadow *shadow = new Shadow();
    ReptilePeople *rept = new ReptilePeople();
    passed = sim(shadow, rept, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete shadow;
    delete rept;
}

void SimulateShadowAgainstGoblin()
{
    bool passed;

    Shadow *shadow = new Shadow();
    Goblin *gob = new Goblin();
    passed = sim(shadow, gob, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete shadow;
    delete gob;
}

void SimulateShadowAgainstBarbarian()
{
    bool passed;

    Shadow *shadow = new Shadow();
    Barbarian *barb = new Barbarian();
    passed = sim(shadow, barb, NUM_TEST_RUNS, 1.0);
    if(passed)
    {
        std::cout << "Passed!" << std::endl;
    }
    else
    {
        std::cout << "failed!" << std::endl;
    }
    delete shadow;
    delete barb;
}

int main()
{

    bool passed;
    srand(time(NULL));



    //test barbarians
    std::cout << "Simulating Barbarian v. Barbarian..." << std::endl;
    SimulateBarbarianAgainstBarbarian();
    std::cout << "Done" << std::endl << std::endl;
    //test reptile people
    std::cout << "Simulating Reptile People vs Reptile People..." << std::endl;
    SimulateReptilePeopleAgainstReptilePeople();
    std::cout << "Done" << std::endl << std::endl;
    //test bluemen vs bluement
    std::cout << "Simulating Blue Men vs Blue Men..." << std::endl;
    SimulateBlueMenAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Goblin vs Goblin..." << std::endl;
    SimulateGoblinAgainstGoblin();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Shadow vs Shadow..." << std::endl;
    SimulateShadowAgainstShadow();
    std::cout << "Done" << std::endl << std::endl;
    //test Barbarian vs. Reptile
    std::cout << "Simulating Reptile People vs Barbarians..." << std::endl;
    SimulateReptilePeopleAgainstBarbarian();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Reptile People vs Blue Men..." << std::endl;
    SimulateReptilePeopleAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Reptile People vs Goblin..." << std::endl;
    SimulateReptilePeopleAgainstGoblins();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Barbarians vs Blue Men..." <<std::endl;
    SimulateBarbariansAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Barbarians vs Goblins..." <<std::endl;
    SimulateBarbariansAgainstGoblins();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Goblins vs Blue Men..." <<std::endl;
    SimulateGoblinsAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Shadow vs Blue Men..." <<std::endl;
    SimulateShadowAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Shadow vs Reptile People..." <<std::endl;
    SimulateShadowAgainstBlueMen();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Shadow vs Goblin..." <<std::endl;
    SimulateShadowAgainstGoblin();
    std::cout << "Done" << std::endl << std::endl;
    //
    std::cout << "Simulating Shadow vs Barbarian..." <<std::endl;
    SimulateShadowAgainstBarbarian();
    std::cout << "Done" << std::endl << std::endl;
    return 0;
}
