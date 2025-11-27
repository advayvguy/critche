#include <stdio.h>
#include <stdlib.h>

int getfile(char *arr)
{
    int i,c;
    for(i = 0; (c = getchar()) != EOF; i++)
    {
        arr[i] = c;
    }
    return i;
}

int main(int argc, char **argv)
{
    char arr[10000];
    int columnarr[1000];
    int strlen = getfile(arr);
    for (int i = 1; i < argc; i++)
    {
        columnarr[i-1] = atoi(*(argv + i));
    }
    int i,j=0,pos;
    for (i = 0; i < strlen; i++)
    {
        if (arr[i] == '\t' && columnarr[j] == i)
        {
            int func = 8 * ((pos-1)/8 + 1) - pos;
            for(int k = 0; k <= func; k++)
            {
                printf(" ");
            }
            pos += func + 1;
        }
        else
        {
            printf("%c",arr[i]);
            pos++;
        }
    }
}