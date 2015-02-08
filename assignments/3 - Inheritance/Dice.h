#pragma once

class Dice
{
public:
    Dice(int numSides);
    virtual int rollDie() const;

protected:
    int numSides;
};