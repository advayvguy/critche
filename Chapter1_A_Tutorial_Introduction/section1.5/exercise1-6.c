#include <stdio.h>

int main()
{
    int c = getchar();

    while (c != EOF)
    {
        int k = (c != EOF);
        printf("%d \n",k);
        c = getchar();
    }
    int k = (c != EOF);
    printf("EOF \n %d \n",k);
}