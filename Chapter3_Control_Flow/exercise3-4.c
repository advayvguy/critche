#include <stdio.h>
#include <string.h>
#include <limits.h>

int itoa(int n, char s[])
{
    int i = 0,sign = n;
    do {
        int digit = (n%10);
        if (digit<0)
        {
            digit = -digit; //when you mod negative numbers you get negative mods surprisingly. I expected negative quotients and positive mods.
        }
        s[i++] = digit + '0';
        n /=10;
    } while (n!=0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    int temp;
    for (int j = 0,k = strlen(s)-1; j<k; j++,k--)
    {
        temp = s[j];
        s[j] = s[k];
        s[k] = temp;
    }
}

int main()
{
    int n = INT_MIN;
    char s[1000];
    itoa(n,s);
    printf("%s\n",s);
}