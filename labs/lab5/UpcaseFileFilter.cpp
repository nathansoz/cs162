#include "UpcaseFileFilter.h"

const int LOWER_TO_UPPER = -32;

char UpcaseFileFilter::transform(char ch)
{
    if((int)ch >= 97 && (int)ch <= 122)
    {
        return (char)((int)ch + LOWER_TO_UPPER);
    }
    else
    {
        return ch;
    }
}