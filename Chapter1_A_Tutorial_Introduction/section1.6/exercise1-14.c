#include <stdio.h>

int main()
{
    int c,i;
    int ascii[128];

    for(i=0 ; i<127; i++)
    {
        ascii[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        ++ascii[c];
    }
    
    for(i=0 ; i<127; i++)
    {
        if (ascii[i] == 0)
        {
            continue;
        }
        else
        {
            printf("------------\n");
            if (i == '\n')
            {
                printf("newl | %4d\n",ascii[i]);
            }
            else if (i == ' ')
            {
                printf("space | %4d\n",ascii[i]);
            }
            else if (i == '\t')
            {
                printf("tab | %4d\n",ascii[i]);
            }
            else
            {
                printf("%5c | %4d\n",i,ascii[i]);
            }
        }
    }
}