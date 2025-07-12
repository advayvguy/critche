#include <stdio.h>

int main()
{
    double nc;
    for(nc = 0; getchar() != EOF; nc++) //i guess if you define double inside a loop, its scope is limited to the loop
    {
        ;
    }
    printf("%.0f\n",nc);
}