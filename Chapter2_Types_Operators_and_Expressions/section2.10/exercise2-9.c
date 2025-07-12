#include <stdio.h>

int main()
{
    int x = 60;
    int b = 0;
    while(x!=0)
    {
        x &= (x-1);
        b++;
    }
    printf("%d\n",b);
}
//This is faster. in the previous step we were running the loop until we reached the bitsize.
//Here the loop just ends when x tends to 0, and the number of steps is the same as the number of 1's
//So 1000000 would take only 1 step rather than 7 in the usual case.