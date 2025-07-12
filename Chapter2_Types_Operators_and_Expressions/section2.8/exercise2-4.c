#include <stdio.h>

void squeeze2(char s1[], char s2[])
{
    int i = 0, j = 0;
    while(s1[i] != '\0')
    {
        if (s1[i] == s2[i])
        {
            i++;
        }
        else
        {
            s1[j++] = s1[i++];
        }
    }
    s1[j] = '\0';
}

int main()
{
    int c,i,j;
    i = 0,j=0;
    char s1[1000];
    char s2[1000];
    while((c = getchar())!='\n')
    {
        s1[i++] = c;
    }
    s1[i] = '\0';
    while((c = getchar())!='\n')
    {
        s2[j++] = c;
    }
    s2[j] = '\0';
    squeeze2(s1,s2);
    printf("%s\n",s1);
}