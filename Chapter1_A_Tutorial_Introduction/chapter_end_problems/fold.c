#include <stdio.h>

int main()
{
    //storing characters in an array
    int c;
    int i =0;
    char array[10000];
    
    // read the line
    while((c = getchar())!=EOF)
    {
        array[i] = c;
        ++i;
    }
    array[i] = '\0';
    int max = i-1;
    //the actual stuff
    int j = 20; //max number of charecters per line

    if(max <= j)
    {
        printf("%s",array);
    }
    else
    {
        int line_start = 0;
        
        while(j <= max)
        {
            if (array[j] == ' ' || array[j] == '\t')
            {
                for(int i = line_start; i<j; i++)
                {
                    printf("%c",array[i]);
                }
                
                line_start = j + 1;
                j += 20;
                printf("\n");
            }
            else
            {
                if (j==line_start)
                {
                    j = line_start + 20;
                    for(int i = line_start; i<=j; i++)
                    {
                        printf("%c",array[i]);
                    }
                    printf("-\n-");
                    line_start = j;
                    j+= 20;
                }
                else
                {
                    j--;
                }
            }
        }
        for (int i = line_start; i<=max; ++i)
        {
            printf("%c",array[i]);
        }
    }
}