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
    int space_count=0;

    //actual code

    for(int pointer =0; pointer<=max; pointer++)
    {
        if (array[pointer] != ' ')
        {
            printf("%c",array[pointer]);
            count--;
        }
        else if(count == 0)
        {
            count = 8;
        }
        else if (array[pointer] == ' ')
        {
            while(array[pointer] != ' ')
            {
                space_count++;
            }
            while(space_count >= count)
            {
                printf("\t");
                space_count = space_count-count;
                count = 8;
            }
            for(int i=0; i<=space_count;i++)
            {
                printf(" ");
            }
            space_count = 0;
        }
    }
}