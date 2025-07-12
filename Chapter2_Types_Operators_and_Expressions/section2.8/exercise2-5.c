#include <stdio.h>

int any(char s1[], char s2[])
{
    for(int i=0; s1[i]!='\0'; i++)
    {
        for(int j=0;s2[j]!='\0';j++)
        {
            if (s1[i] == s2[j])
            {
                return i; //return i just ends this function
            }
        }
    }
    return -1;
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
    printf("%d\n",any(s1,s2));
}