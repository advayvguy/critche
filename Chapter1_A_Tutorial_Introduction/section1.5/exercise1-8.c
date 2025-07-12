#include <stdio.h>

int main()
{
    int blanks = 0;
    int tabs = 0;
    int new_lines = 0;
    int c;

    while((c=getchar()) != EOF)
    {
        if (c == '\n')
        {
            new_lines++;
        }
        if (c == '\t')
        {
            tabs++;
        }
        if (c == ' ')
        {
            blanks++;
        }
    }
    printf("new lines: %3d \n tabs: %7d \n blanks: %5d \n",new_lines,tabs,(blanks+4*tabs));
}   
