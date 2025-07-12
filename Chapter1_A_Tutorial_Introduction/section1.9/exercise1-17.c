//slightly modified to print everything over 30 characters rather than 80
#include <stdio.h>

int main()
{
    char line[1000];
    int i;

    int c = getchar();
    while (c != EOF)
    {
        i = 0;
        while(c != '\n')
        {
            line[i] = c;
            c = getchar();
            ++i;
        }
        line[i] = '\0';

        if (i >= 30)
        {
            printf("%s\n",line);
        }
        c = getchar();
    }
}