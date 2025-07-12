#include <stdio.h>

int main()
{
    char line[1000];
    int c;
    int i;

    c = getchar();
    while (c != EOF)
    {
        i = 0;
        while (c != '\n')
        {
            line[i] = c;
            ++i;
            c = getchar();
        }
        line[i] = '\0';
        if (line[0] != '\n')
        {
            for(i;i>=0;--i)
            if (line[i] != '\t' || line[i] != ' ')
            {
                printf("there were trailing spaces or tabs and they have been removed \n");
                break;
            }
            else
            {
                line[i] = '\0';
            }

            printf("%s\n",line);
        }

        c = getchar();
    }
}