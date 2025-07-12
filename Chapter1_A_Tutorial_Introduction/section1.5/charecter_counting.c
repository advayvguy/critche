#include <stdio.h>

int main()
{
    int c = getchar();
    long nc = 0;

    while(c != EOF)
    {
        ++nc;
        c = getchar();
    }

    printf("%ld \n",nc);
}