#include <stdio.h>
#include <string.h>
//absolutely lovely... worked on first try.

void expand(char s1[],char s2[])
{
    int j = 0;
    for(int i = 0; i<strlen(s1); i++)
    {
        if (s1[i] == '-' && s1[i-1] < s1[i+1] && ((s1[i-1] >= 'a' && s1[i+1] <= 'z') || (s1[i-1] >= '0' && s1[i+1] <= '9') || (s1[i-1] >= 'A' && s1[i+1] <= 'Z')))
        {
            for (int k = s1[i-1] + 1; k< s1[i+1]; k++)
            {
                s2[j] = k;
                j++;
            }
        }
        else 
        {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';
}

int main()
{
    int c,i;
    char s1[1000],s2[1000];
    for(i = 0; (c = getchar())!=EOF; i++)
    {
        s1[i] = c;
    }
    s1[i] = '\0';
    expand(s1,s2);
    printf("%s\n",s2);
}