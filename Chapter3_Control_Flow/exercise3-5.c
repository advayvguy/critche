#include <stdio.h>
#include <string.h>

void itob(int n, char s[],int b)
{
    int i = 0,sign;
    if ((sign = n)<0)
    {
        n = -n;
    }
    do{
        if (n%b <= 9)
        {
            s[i++] = n%b + '0';
        }
        else
        {
            s[i++] = (n%b - 10) + 'A';
        }
    } while ((n/=b) > 0);
    if (sign <0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    int temp;
    for (int i = 0, j = (strlen(s)-1); i<j; i++,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main()
{
    int n = 43212;
    char s[1000];
    int b = 16;
    itob(n,s,b);
    printf("%s\n",s);
}