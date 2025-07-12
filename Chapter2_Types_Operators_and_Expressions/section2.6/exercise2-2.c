#include <stdio.h>
#define LIM 1000

int main()
{
    char s[LIM];
    int c,i;
    i=0;
    while((c = getchar())!=EOF)
    {
        if(i==LIM-1)
        {
            break;
        }
        s[i] = c;
        i++;
    }
    s[i] == '\0';
    printf("%s",s);
}