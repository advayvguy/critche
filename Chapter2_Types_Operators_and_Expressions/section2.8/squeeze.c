#include <stdio.h>

void squeeze(char s[],int c)
{
    int i,j;
    for(i=j=0;s[i] != '\0';i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
int main()
{
    int c,i;
    i = 0;
    char s[1000];
    while((c = getchar())!=EOF)
    {
        s[i++] = c;
    }
    s[i] = '\0';
    squeeze(s,'c'); //whatever charecter you dont want.
    printf("%s\n",s);
}