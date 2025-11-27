//finally works
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getfile(char arr[])
{
    int c,i;
    for (i = 0; (c = getchar()) != EOF; i++)
    {
        arr[i] = c;
    }
    arr[i] = '\0';
}

int main(int argc, char **argv)
{
    char buff[1000];
    getfile(buff);
    int len = strlen(buff);
    int carray[1000];
    for(int i = 1; i < argc; i++)
    {
        carray[i-1] = atoi(argv[i]);
    }
    int curclm=0,i;
    for (i = 0; i < len; i++)
    {
        if (i > carray[curclm] && curclm < argc)
        {
            curclm++;
        }
        if (carray[curclm] == i)
        {
            int func = ((i / 8) + 1) * 8,j;
            for (j = i; buff[j] == ' ' && j < func;j++)
            {
                ;
            }
            if (j >= func-1)
            {
                printf("\t");
                i = func-1;
            }
            else 
            {
                printf("%c",buff[i]);
            }
        }
        else
        {
            printf("%c",buff[i]);
        }
    }
    printf("\n");
}