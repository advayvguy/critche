#include <stdio.h>
#include <string.h>
#define MAXSIZE 100000

int getint(char *str)
{
    if (*str == '\0')
    {
        return -1;
    }
    int len = strlen(str);
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        if (*(str + i) < '0' || *(str + i) > '9')
        {
            return -1;
        }
        sum = 10*sum + (*(str + i) - '0');
    }
    return sum;
    
}

int count_and_add(char *buf, int *i)
{
    int lines = 0,c;
    for (*i = 0; (c = getchar()) != EOF; (*i)++)
    {
        if (*i == MAXSIZE)
        {
            return -1;
        }
        if (c == '\n')
        {
            buf[*i] = '\n';
            lines++;
        }
        else
        {
            buf[*i] = c;
        }
    }
    return lines;
}

void printlastn(int lines, int num, char *buf,int lim)
{
    int last = lines - num;
    if (last < 0)
    {
        last = 0;
    }
    int check = 0;
    for(int i = 0; i < lim; i++)
    {
        if (check >= last)
        {
            printf("%c",*(buf+i));
        }
        else
        {
            if (*(buf+i) == '\n')
            {
                check++;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int num = 10,i;
    char buf[MAXSIZE];
    if (argc > 1 && **(argv + 1) == '-')
    {
        int n = getint(*(argv + 1) + 1);
        if (n < 0)
        {
            printf("error in line number, should be of format <tail -n> where n>0\n");
            return 0;
        }
        num = n;
    }
    int lines = count_and_add(buf,&i);
    if (lines < 0)
    {
        printf("buffer size exceeded\n");
        return 0;
    }
    printf("-----------------------------------\n");
    printlastn(lines,num,buf,i);
}
