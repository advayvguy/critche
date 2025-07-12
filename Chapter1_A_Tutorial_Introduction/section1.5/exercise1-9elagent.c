#include <stdio.h>

int main()

{
    int c;
    int inspace = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (inspace == 0)
            {
                inspace = 1;

            }
            else
            {
                continue;
            }
        }
        else if (inspace == 1)
        {
            inspace = 0;
        }
        
        putchar(c);
    }
}