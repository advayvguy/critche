#include <stdio.h>

int check(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int digit = n%10;
        int current= check(n/10);
        int c = (digit%2 == 0);
        if (current == 0)
        {
            if (c) 
            return 0;
            else
            return 1;
        }
        else
        {
            if (c)
            return 1;
            else
            return 0;
        }
    }
}

int main()
{
    int i = 1;
    while (i != -1)
    {
        scanf("%d",&i);
        printf("%d\n",check(i));
    }
}
