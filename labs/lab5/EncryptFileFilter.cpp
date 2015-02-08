#include <iostream>
#include "EncryptFileFilter.h"

EncryptFileFilter::EncryptFileFilter(int encryptKey)
{
    this->encryptKey = encryptKey;
}

char EncryptFileFilter::transform(char ch)
{
    if((int)ch >= 65 && (int)ch <= 90)
    {
        return (((((int)ch) + this->encryptKey) % 26) + 65);
    }
    else if((int)ch >= 97 && (int)ch <= 122)
    {
        return (((((int)ch) + this->encryptKey) % 26) + 97);
    }
    else
    {
        return ch;
    }


}