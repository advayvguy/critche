#include <stdio.h>

int main()
{
    int in = 1; int out = 0;
    int nw = 0; int c;

    int state = out;

    while ((c = getchar())!= EOF)

    if (c == '\n' || c == '\t' || c == ' ')
    {
        state = out;
        continue; //i dont think you need this though
    }
    else if (state == out) // the next character after a series of spaces 
    {
        state = in;
        nw++;
    }
    printf("number of words: %d \n",nw);
}