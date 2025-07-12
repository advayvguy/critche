#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
    return (x>>(p-n+1)&~(~0<<n)) | (y&(~0<<n));
}
int main()
{
    int x = 63, p = 4, n = 3, y = 30;
    printf("%d\n",setbits(x,p,n,y));
}