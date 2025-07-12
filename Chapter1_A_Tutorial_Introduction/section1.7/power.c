#include <stdio.h>

int power(int base, int exp)
{
    int p = 1;
    for (int i=0; i<=exp; i++)
    {
        p = p*base;
    }
    return p;
}

int main()
{
    int i;

    for(i=0;i<11;i++)
    {
        printf("%3d %6d %6d\n",i,power(2,i),power(3,i));
    }
}