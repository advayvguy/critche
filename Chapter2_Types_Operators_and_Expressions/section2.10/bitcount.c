#include <stdio.h>

int main()
{
    int x = 62;
    int b;
    for (b = 0; x!=0; x >>= 1)
    {
        if(x&1)
        {
            b++;
        }
    }
    printf("%d\n",b);
}