//Pretty good stuff I guess, although the double loop could be replaced by recursion. Will look into it some time later.
#include <stdio.h>

int main()
{
    int list[20];
    for (int i=0;i<20;i++)
    {
        list[i] = 0;
    }
    int c;
    int len = 0;
    while ((c = getchar())!=EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if(len != 0)
            {
            ++list[len];
            len = 0;
            }
        }
        else
        {
            ++len;
        }
    }
    int max = 0;
    int j = 20;
    int maxindex = 0;
    for(int i = 0; i<20;i++)
    {
        j--;
        if (list[j] != 0)
        {
            if(j > maxindex)
            {
                maxindex = j;
            }
        }
        if (list[i]>max)
        {
            max = list[i];
        }
    }
    for(int i = 0; i<20; ++i)
    {
        list[i] = (list[i]*20)/max;
    }
    int level = max;
    max = 20;
    while (max != 0)
    {
        printf("%2.1f",(level*max)/20.0);
        for(int i = 0; i<20; i++)
        {
            if(list[i] >= max)
            {
                printf("  |");
            }
            else
            {
                printf("   ");
            }
        }
        --max;
        printf("\n");
    }
    printf("   ");
    for(int i = 0; i<=maxindex; ++i)
    {
        printf(" %2d",i);
    }
    printf("\n");
}