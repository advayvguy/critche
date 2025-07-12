#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar())!= EOF)
    {
        if (c == '\t')
        {
            c = '\b';
        }
        else if (c =='\\')
        {
            putchar(c);
            putchar(c);
            continue;
        }
    putchar (c);
    }
}