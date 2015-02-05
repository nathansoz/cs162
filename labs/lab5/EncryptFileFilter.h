#pragma once

#include "FileFilter.h"

class EncryptFileFilter : public FileFilter
{
public:
    EncryptFileFilter(int encryptKey);
private:
    int encryptKey;

    virtual char transform(char ch);

};