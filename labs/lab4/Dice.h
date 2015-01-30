#pragma once

class Dice
{
public:
    Dice();
    Dice(int numSides);

    virtual int rollDice() const;

protected:
    int numSides;
};