#include <stdio.h>

void join(char s[], char t[])
{
    int i = 0, j = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    while((s[i++] = t[j++]) != '\0')
    {
        ;
    }
}
int main()
{
    int c,i,j;
    i = 0,j=0;
    char s[1000];
    char t[1000];
    while((c = getchar())!='\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    while((c = getchar())!='\n')
    {
        t[j++] = c;
    }
    s[j] = '\0';
    join(s,t);
    printf("%s\n",s);
}