#include <stdio.h>

void escape(char s[],char t[])
{
    int i = 0,j=0;
    while (s[i] != '\0')
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
        default:
            t[j++] = s[i];
            break;
        }
        i++;
    }
    t[j] = '\0';
}

int main()
{
    int c,i;
    char s[1000], t[1000];
    for(i = 0; (c = getchar())!=EOF; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    escape (s,t);
    printf("%s \n",t);
}