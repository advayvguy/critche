#include <stdio.h>

void copy(char to[], char from[])
{
    int i=0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}

int mygetline(char s[], int lim) //stores the value of the line and its length 
{
    int c,i;

    for(i=0; i<lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
    {
        s[i] = c;
    }

    if (c== '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

int main()
{
    int len; //length of the current line
    int max; //maximum length we have seen so far
    int MAXLINE = 1000;
    char line[MAXLINE]; //current input line
    char longest[MAXLINE]; //logest line we have seen

    max = 0;
    while ((len = mygetline(line,MAXLINE)) > 0)
    {
        if(len>max)
        {
            max = len;
            copy(longest,line);
        }
    }
    if (max>0)
        printf("%s",longest);
    return 0;
}