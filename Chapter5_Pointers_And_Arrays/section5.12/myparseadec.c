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
        ✅ to make the code more modular <- number 1 priority
        ✅ to handle paranthesis matching
        ✅ function type declarations shouldnt be hard either, just need print statements
        ✅ if you encounter const/static/global then read the next word ahead of the white spaces
*/

/*
    mostly functional in its domain, altough i rekon that the code could have been a little more cleaner.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 500

enum Ops {pointer, array, function};

void reverse(char *s, int len)
{
    char t[MAXCHAR];
    for (int i = 0; i < len; i++)
    {
        t[i] = s[len-i-1];
    }
    t[len] = '\0';
    strcpy(s,t);
}

//getline looking kinda stacked rn
int get_line(char *s, char *type)
{
    int i = 0,c; 
    while ((c = getchar()) == ' ' || c == '\t');
    type[i++] = c;

    while ((c = getchar()) != ' ' &&  c != '\t' && c != '\n') type[i++] = c;
    type[i] = '\0';
    
    if (strcmp(type,"const") == 0 || 
        strcmp(type,"unsigned") == 0 || 
        strcmp(type,"signed") == 0 || 
        strcmp(type,"long") == 0 ||
        strcmp(type,"global") == 0 ||
        strcmp(type,"static") == 0
        )
    {
        type[i++] = ' ';
        while ((c = getchar()) != ' ' &&  c != '\t' && c != '\n') type[i++] = c;
        type[i] = '\0';
    }

    i = 0;
    while (c == ' ' || c == '\t') c = getchar();
    s[i++] = c;

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
    int par_check = 0, par_len = 0,func_check = 0;
    char par[MAXCHAR];
    if (s[last] != ']' && s[last] != ')' && s[first] != '*')
    {
        while (first <= last)
        printf("%c", s[first++]);
        printf(" :- ");
        return;  
    }
    if (s[last] == ')')
    {
        while (s[last-par_len-1] != '(' && last-par_len-1 >= 0)
        {
            par[par_len] = s[last-par_len-1];
            par_len++;
        }
        if (first == last - par_len-1) par_len = 0;
        par[par_len] = '\0';
    }
    if (s[first] == '(' && s[last] == ')' && s[last-1-par_len] != '(')
    {
        parser(s, first + 1, last - 1,F);
    }
    else if (s[first] == '*')
    {
        parser(s, first+1, last,F);
        printf("pointer to ");
    }
    else if (s[first] == '(' && s[first + 1] == '*' && *F == 0)
    {
        *F = 1;
        parser(s, first + 2,last, F);
    }
    else if (s[last] == ')' && s[last - 1-par_len] == '(')
    {
        if (*F == 1)
        {
            *F = 0;
            parser(s, first, last - 3-par_len, F);
            printf("pointer to ");
        }
        else parser(s, first, last - 2-par_len, F);
        if (par_len == 0) printf("function returning ");
        else
        {
            printf("function accepting ");
            reverse(par, par_len);
            printf("%s ",par);
            printf("and returning ");
        }
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
    int stack_check_1 = 0, stack_check_2 = 0;
    for (int i = first; i <= last; i++)
    {
        if (s[i] == '(') stack_check_1++;
        if (s[i] == '[') stack_check_2++;
        if (s[i] == ')')
        {
            stack_check_1--;
            if (stack_check_1 < 0) 
            {
                printf("error: paranthesis mismatch, expected- \'(\'\n");
                return -1;
            }
        }
        if (s[i] == ']')
        {
            stack_check_2--;
            if (stack_check_2 < 0)
            {
                printf("error: paranthesis mismatch, expected- \'[\'\n");
                return -1;
            }
        }
    }
    if (stack_check_1 > 0)
    {
        printf("error: paranthesis mismatch, expected-  \')\'\n");
        return -1;
    }
    if (stack_check_2 > 0)
    {
        printf("error: paranthesis mismatch, expected- \']\'\n");
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
