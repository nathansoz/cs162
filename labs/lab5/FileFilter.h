#pragma once

#include <fstream>

class FileFilter
{
public:
    virtual void doFilter(std::ifstream &in, std::ofstream &out);

private:
    virtual char transform(char ch) = 0;
};