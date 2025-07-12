#include <stdio.h>

int getbits(int x, int p, int n)
{
    return (x >> (p-n+1)) & ~(~0 << n);
}

int main()
{
    int x = 63, p = 4, n = 3;
    printf("bits= %d\n",getbits(x,p,n));
}