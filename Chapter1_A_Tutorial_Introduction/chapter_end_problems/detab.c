#include <stdio.h>

int main()
{
    //storing the data
    int i = 0;
    int c;
    char array[10000];

    while ((c = getchar())!=EOF)
    {
        array[i] = c;
        i++;
    }
    array[i] = '\0';
    int max = i-1;
    int count = 8;
    //the code
    for(int pointer = 0; pointer<=max; pointer++)
    {
        if(array[pointer]!= '\t')
        {
            printf("%c",array[pointer]);
            count--;
        }
        else if(count == 0)
        {
            count = 8;
            pointer--;
        }         
        else if(array[pointer] == '\t')
        {
            for (int i = 0; i<count;i++)
            {
                printf(" ");
            }
            count = 8;
        }      
    }
}