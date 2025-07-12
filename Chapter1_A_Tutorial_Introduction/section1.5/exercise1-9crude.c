#include <stdio.h>

int main()

{
    int c;
    int prevc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (prevc == ' ')
            {
                c = 0;
                prevc = ' ';

            }
            else
            {
                c = ' ';
                prevc = ' ';
            }
        }
        else
        {
            prevc = c;
        }
        
        putchar(c);
    }
}