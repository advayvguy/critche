#include <stdio.h>

int main()
{
    int c,i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i<10; i++)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar())!= EOF)
    {
        if (c >= '0' && c <= '9') //we know that these values are consequitively increasing in ascii standard
        {
            ++ndigit[c-'0'];  // say 5's charecter is 10025 then 0's charecter value is 10020. what we want to save however is not the charecter value but the value of int itself. therfore c-0 gives us 5 in this case
        }
        else if (c == ' ' || c == '\n' || c=='\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }
    for (i = 0; i<10; i++)
    {
        printf("%d-%d ",i,ndigit[i]);
    }
    printf("\n white space- %d, other charecters- %d \n",nwhite,nother);
}

//i just searched, the charecter '0's ascii value is 48
//after the if statement is completed it doesnt move down to else even if its initial condition satisfies else
