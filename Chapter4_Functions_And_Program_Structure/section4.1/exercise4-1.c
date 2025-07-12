#include <stdio.h>
#include <string.h>

int strrindex(char s[],int t)
{
    int j;
    for (j = 0; j < strlen(s);j++)
    {
        if (s[j] == t)
        {
            return (strlen(s) - j);
        }
    }
    return -1;
}

void read_file(char s[])
{
    int c,i;
    for (i=0;(c= getchar())!=EOF;i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
}

int main()
{
    char s[1000];
    read_file(s);
    int t = 'c';
    printf("%d\n",strrindex(s,t));
}