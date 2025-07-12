//F-32/180 = C/100 -> C = 5/9(F-32)
//we want to print a table which converts fahrenheit to celcius (from 0 to 300 with common differene of 20)
#include <stdio.h>

int main()
{
    int F,C,step,lower,upper;

    step = 20;
    lower = 0;
    upper = 300;

    F = lower;

    while (F<=upper)
    {
        //C = 5/9*(F-32); ->note that this doesnt work because it converts 5/9 to 0
        C = 5*(F-32)/9;
        printf("%d\t%d\n",F,C); //%d indicates an integer argument 
                                //%3d means to print an integer after 3 spaces
        F = F + step;
    }
}

//i cant print F directly, i need to use %d, cant printf only print strings or does %d mean something else

//float is 32 bit quantity and isnt stored traditionally as int. it uses some kind of a power system and ranges from 10^-38 to 10^38
