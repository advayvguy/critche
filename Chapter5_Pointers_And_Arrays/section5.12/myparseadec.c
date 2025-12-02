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

//getline looking kinda stacked rn
int get_line(char *s, char *type)
{
    int i = 0,c; 
    while ((c = getchar()) == ' ' || c == '\t');
    type[i++] = c;
    while ((c = getchar()) != ' ' &&  c != '\t' && c != '\n')
    {
        type[i++] = c;
    }
    type[i] = '\0';
    i = 0;
    if (c == '\n' && strcmp(type, "exit") == 0) return -1;
    else if (c == '\n')
    {
        printf("error: declaration doesnt declare anything\n");
        return -1;
    }
    while ((c = getchar()) != '\n' && i < MAXCHAR)
    {
        if (c == ' ' || c == '\t') continue;
        else s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void parser(char *s, int first, int last, int *F)
{
    if (s[last] != ']' && s[last] != ')' && s[first] != '*')
    {
        while (first <= last)
        printf("%c", s[first++]);
        printf(" :- ");
        return;  
    }
    else if (s[first] == '(' && s[last] == ')' && s[first + 1] != '*')
    {
        parser(s, first + 1, last - 1,F);
    }
    if (s[first] == '*')
    {
        parser(s, first+1, last,F);
        printf("pointer to ");
    }
    else if (s[first] == '(' && s[first + 1] == '*' && *F == 0)
    {
        *F = 1;
        parser(s, first + 2,last, F);
    }
    else if (s[last] == ')' && s[last - 1] == '(')
    {
        if (*F == 1)
        {
            *F = 0;
            parser(s, first, last - 3, F);
            printf("pointer to ");
        }
        else parser(s, first, last - 2, F);
        printf("function returning ");
    }
    else if (s[last] == ']')
    {
        if (s[last - 1] == '[')
        {
            if (*F == 1)
            {
                *F = 0;
                parser(s, first, last - 3, F);
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
            if (*F == 1)
            {
                *F = 0;
                parser(s, first, last-2, F);
                printf("pointer to ");
            }
            else parser(s, first, last-1, F);
            printf("array[%d] of ", num);
        }
    }
}

int check_para(char *s, int first, int last)
{
    int stack_check = 0;
    for (int i = first; i <= last; i++)
    {
        if (s[i] == '(') stack_check++;
        if (s[i] == ')')
        {
            stack_check--;
            if (stack_check < 0) 
            {
                printf("error: unexpected \')\'\n");
                return -1;
            }
        }
    }
    if (stack_check > 0)
    {
        printf("error: unexpected \'(\'\n");
        return -1;
    }
    return 0;
}

int main()
{
    char buff[MAXCHAR];
    int len;
    char type[MAXCHAR];
    printf("----TYPE \"exit\" TO END THE PROGRAM----\n");
    while ((len = get_line(buff,type)) >= 0)
    {
        int last = len - 1;
        int para_check = check_para(buff,0,last);
        if (para_check < 0) continue;
        int flag = 0;
        int *F = &flag;
        int i = 0;
        if (buff[last] == ';') last--;
        parser(buff, i, last, F);
        //if (*F < 0) return 1;
        printf("%s\n",type);
    }

    printf("----END OF PROGRAM----\n");
}