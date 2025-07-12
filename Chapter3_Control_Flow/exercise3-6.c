#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int width)
{
    int i ,sign;
    if ((sign = n) < 0)
    {
        n = -n;
    }
    for (i = 0; i<width; i++)
    {
        if (sign <0 && n == 0)
        {
            s[i] = '-';
            sign = 1;
        }
        else if (sign >0 && n == 0)
        {
            s[i] = ' ';
        }
        else
        {
            s[i] = n%10 + '0';
            n /= 10;
        }
    }
    s[i] = '\0';
    int temp;
    for(int j =0,k=strlen(s) -1; j<k; j++,k--)
    {
        temp = s[j]; 
        s[j] = s[k];
        s[k] = temp;
    }
}

int main()
{
    char s[1000];
    int n = -4375;
    int width = 10;
    itoa(n,s,width);
    printf("%s\n",s);
}