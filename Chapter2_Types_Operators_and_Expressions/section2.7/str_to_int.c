//what is the deal with '2' and 2;
//look here dude when you just write c = 2, it associates c to the 2 in the ascii table.

#include <stdio.h>

int atoi(char string[])
{
    int n = 0;
    for(int i = 0; i<4;i++)
    {
        n = n*10 + (string[i] - '0');
    }
    return n;
}

int main()
{
    char s[] = "2556";
    printf("the number is: %d \n",atoi(s));
}