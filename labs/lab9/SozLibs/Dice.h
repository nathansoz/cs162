#pragma once

namespace SozLibs {

    class Dice
    {
    public:
        Dice(int numSides);

        virtual int rollDie() const;

    protected:
        int numSides;
    };

}