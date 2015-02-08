#pragma once

#include "EncryptFileFilter.h"

class GroupEncryptFileFilter : public FileFilter
{
public:
    virtual void doFilter(std::ifstream &in, std::ofstream &out);
    GroupEncryptFileFilter(int encryptKey);
private:
    int encryptKey;
    int charCounter;
    virtual char transform(char ch);

};