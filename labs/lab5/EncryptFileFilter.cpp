#include "EncryptFileFilter.h"

EncryptFileFilter::EncryptFileFilter(int encryptKey)
{
    this->encryptKey = encryptKey;
}

char EncryptFileFilter::transform(char ch)
{
    return ((ch + this->encryptKey) % 26);
}