#pragma once

#include "FileFilter.h"

class UpcaseFileFilter : public FileFilter
{
private:
    virtual char transform(char ch);
};