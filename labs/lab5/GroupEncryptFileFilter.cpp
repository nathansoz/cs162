#include "GroupEncryptFileFilter.h"
#include <fstream>

GroupEncryptFileFilter::GroupEncryptFileFilter(int encryptKey)
{
    this->encryptKey = encryptKey;
}

//we need to do more than the base class does, so we have to define a new implementation
void GroupEncryptFileFilter::doFilter(std::ifstream &in, std::ofstream &out)
{
    this->charCounter = 0;

    while((in.peek() != EOF))
    {

        char inChar;
        char outChar;

        if(this->charCounter >= 5)
        {
            out.put(' ');
            this->charCounter = 0;
            continue;
        }
        else if(in.peek() == ' ' || in.peek() == '\n')
        {
            //grab the input and throw it away
            in.get(inChar);
            continue;
        }
        else
        {
            in.get(inChar);
            outChar = transform(inChar);
            out.put(outChar);
            this->charCounter++;
        }
    }
}

char GroupEncryptFileFilter::transform(char ch)
{
    if(((int)ch >= 65 && (int)ch <= 90) || ((int)ch >= 97 && (int)ch <= 122))
    {
        return (((((int) ch) + this->encryptKey) % 26) + 65);
    }
    else
    {
        return ch;
    }
}