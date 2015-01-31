/* Author: Nathan Sosnovske
*
* Created: 1/09/15
*
* Edited: 1/09/15
*
* Files: lab1-1.cpp
*
* Overview:
* Sorts 3 numbers
*
* Input:
*  none
*
* Output:
*  three numbers, sorted
*
*/

#include <iostream>

void SortThreeNumbers(int *a, int *b, int *c)
{
    while (*a > *b || *b > *c) {
        if (*a > *b) {
            int tmp = *a;
            *a = *b;
            *b = tmp;
        }
        else if (*b > *c)
        {
            int tmp = *b;
            *b = *c;
            *c = tmp;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int x = 2;
    int y = 5;
    int z = 1;

    std::cout << x << " " << y << " " << z << std::endl;

    SortThreeNumbers(&x, &y, &z);

    std::cout << x << " " << y << " " << z << std::endl;

    return 0;
}
