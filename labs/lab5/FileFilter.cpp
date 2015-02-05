#include "FileFilter.h"

//assumes that the stream has been opened
void FileFilter::doFilter(std::ifstream &in, std::ofstream &out)
{
    while((in.peek() != EOF))
    {
        char inChar;
        char outChar;
        in.get(inChar);
        outChar = transform(inChar);
        out.put(outChar);
    }

}