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
    int a = 3;
    int b = 1;
    int c = 2;

    std::cout << a << " " << b << " " << c << std::endl;

    SortThreeNumbers(&a, &b, &c);

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}