#include <stdio.h>

int rightrot(int x, int n)
{
    int bitsize;
    int temp = x;
    while(temp != 0)
    {
        temp >>= 1; //clever technique. i was trying to compute the power using float. it did work though
        bitsize++;
    }
    if (bitsize == 0)
    {
        return x;
    }
    n = n%bitsize //in case bitsize > n
    int shifted = (x>>n);
    int y = ((x<<(bitsize-n))&~(~0 << bitsize));
    return (shifted | y);
}

int main()
{
    int x= 19, n = 10;
    printf("%d\n",rightrot(x,n));
}