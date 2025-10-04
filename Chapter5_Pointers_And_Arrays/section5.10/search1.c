#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 10000

int get_line(char *line, int max)
{
    int c,i;
    for  (i = 0; (c = getchar()) != '\n'; i++)
    {
        if (c == EOF)
        {
            printf("end of program\n");
            return -1;
        }
        if (i == max)
        {
            printf("reached size limit\n");
            return 1;
        }
        *(line + i) = c;
    }
    *(line + i) = '\0';
    return 1;
}
int main(int argc, char **argv)
{
    char line[MAXLINE];
    int found = 0;
    if (argc != 2)
    {
        printf("error: specify one word\n");
    }
    else
    {
        while(get_line(line,MAXLINE) > 0)
        {
            if (strstr(line, argv[1]) != 0) //returns null if no such character exists.
            {
                printf("%s\n",line);
                found++;
            }
        }
    }
    return found;
}