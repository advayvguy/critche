/* 
extra steps to perform after the main program is written-
dcl should recover from input errors
write an undcl program as well, it should not add redundent parantheses 
Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
*/

/*
dcl- parse C declaration to an output which is human readable
undcl- parse human readable input to a declaration
*/

/*
    betterments-
        to make the code more modular <- number 1 priority
        to handle paranthesis matching
        function type declarations shouldnt be hard either, just need print statements
        if you encounter const/static/global then read the next word ahead of the white spaces
        writing undcl shouldnt be too hard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 500

enum Ops {pointer, array, function};

int get_line(char *s)
{
    int i,c; 
    for (i = 0; i < MAXCHAR && (c = getchar()) != '\n'; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    if (strcmp(s, "exit") == 0) return -1;
    return i;
}

void parser(char *s, int first, int last, int flag)
{
    while (s[first] == ' ' || s[first] == '\t') first++;
    while (s[last] == ' ' || s[last] == '\t') last--;
    if (s[last] != ']' && s[last] != ')' && s[first] != '*')
    {
        while (first <= last)
        printf("%c", s[first++]);
        printf(" :- ");
        return;  
    }
    else if (s[first] == '(' && s[last] == ')' && s[first + 1] != '*')
    {
        parser(s, first + 1, last - 1,flag);
    }
    else if (s[first] == '*')
    {
        parser(s, first+1, last,0);
        printf("pointer to ");
    }
    else if (s[first] == '(' && s[first + 1] == '*' && flag == 0)
    {
        parser(s, first + 2,last, 1);
    }
    else if (s[last] == ')' && s[last - 1] == '(')
    {
        if (flag == 1)
        {
            parser(s,first, last - 3, 0);
            printf("pointer to ");
        }
        else parser(s, first, last - 2, 0);
        printf("function returning ");
    }
    else if (s[last] == ']')
    {
        if (s[last - 1] == '[')
        {
            if (flag == 1)
            {
                parser(s, first, last - 3, 0);
                printf("pointer to ");
            }
            else parser(s, first, last - 2, 0);
            printf("array[] of ");
        }
        else if (isdigit(s[last-1]))
        {
            int num = 0, place = 1;
            last--;
            while (last >= first && isdigit(s[last])) 
            {
                num += (s[last] - '0') * place;
                place *= 10;
                last--;
            }
            if (flag == 1)
            {
                parser(s,first,last-2,0);
                printf("pointer to ");
            }
            else parser(s,first,last-1,0);
            printf("array[%d] of ", num);
        }
    }
}

int main()
{
    char buff[MAXCHAR];
    int len;
    printf("----TYPE \"exit\" TO END THE PROGRAM----\n");
    while ((len = get_line(buff)) >= 0)
    {
        //check 1 satsified:- the input is being read properly here

        char type[MAXCHAR];
        int i = 0;
        for (i = 0; buff[i] != '\0' && buff[i] != ' ' && buff[i] != '\t'; i++)
        {
            type[i] = buff[i];
        }
        type[i] = '\0';
        //check 2 stisfied:- able to store the type properly here

        int last = len - 1;
        parser(buff,i, last,0);
        printf("%s\n",type);
    }

    printf("----END OF PROGRAM----\n");
}