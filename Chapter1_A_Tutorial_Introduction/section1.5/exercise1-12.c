#include <stdio.h>

int main()

{
    int c; int in = 1; int out = 0; int state; int nw =0;

    state = in;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t')
        {
            state = out;
        }
        else if (state == out)
        {
            putchar('\n');
            putchar(c);
            state = in;
        }
        else
        {
            putchar(c);
        }
    }
}