#include <stdio.h>

int invert (int x, int p, int n)
{
    return (x)^((~(~0<<n))<<(p-n+1));
}

int main()
{
    int x = 63, p = 4, n = 3;
    printf("bits= %d\n",invert(x,p,n));
}