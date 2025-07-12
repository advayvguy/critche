#include <stdio.h>

int main()
{
    int i;
    int max;
    int c;
    char to[1000];
    char from[1000];

    c = getchar();
    while (c != EOF)
    {
        i = 0;
        while (c != '\n' && i <1000)
        {
            from[i] = c;
            c = getchar();
            ++i;
        }
        from[i] = '\0';
        max = i-1;

        for(i=0; from[i] != '\0'; i++)
        {
            to[i] = from[max];
            --max;
        }
        to[i] = '\0'; 
        printf("%s\n",to);  

        c = getchar();
    }
}