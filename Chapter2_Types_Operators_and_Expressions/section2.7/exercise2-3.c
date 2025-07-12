#include <stdio.h>
#include <math.h>

int htoi(char string[],int max)
{
    int n = 0;
    for (int i = max; i >= 0;--i)
    {
        int r = pow(16,max-i);
        if(string[i] >= '0' && string[i] <= '9')
        {
            n = n + (string[i] - '0')*r;
        }
        else if (string[i] >= 'A' && string[i] <= 'F')
        {
            n = n + (string[i] - 'A' + 10)*r;
        }
        else if (string[i] >= 'a' && string[i] <= 'f')
        {
            n = n + (string[i] - 'a' + 10)*r;
        }
    }
    return n;
}

int main()
{
    char s[1000];
    int i = 0;
    int c;


    while((c = getchar())!=EOF)
    {
        if (c == '\n')
        {
            break;
        }
        s[i] = c;
        i++;
    }    
    s[i] = '\0';
    int max;
    if (s[0] == 0 && (s[1] == 'x' || s[1] == 'X'))
    {
        max = i-3;
    }
    else
    {
        max = i-1;
    }
    printf("the decimal value is %d\n",htoi(s,max));
}