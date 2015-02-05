#pragma once

#include "FileFilter.h"

class CopyFileFilter : public FileFilter
{
private:
    virtual char transform(char ch);
};