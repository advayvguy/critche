#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NKEYS (sizeof keytab/sizeof (struct key))
#define MAXWORD 100

struct key
{
    char *word;
    int count;
};

struct key keytab[] =
{
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "do", 0,
    "double", 0,
    "else", 0,
    "enum", 0,
    "extern", 0,
    "float", 0,
    "for", 0,
    "goto", 0,
    "if", 0,
    "int", 0,
    "long", 0,
    "register", 0,
    "return", 0,
    "short", 0,
    "signed", 0,
    "sizeof", 0,
    "static", 0,
    "struct", 0,
    "switch", 0,
    "typedef", 0,
    "union", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

int unget = '\0';

char getch()
{
    if (unget == '\0') return getchar();
    else
    {
        int temp = unget;
        unget = '\0';
        return temp;
    }
}

void ignore_spaces()
{
    int c;
    while ((c = getch()) == ' ' || c == '\t' || c == '\n') ;
    unget = c;
}

int getword(char *word,int max)
{
    ignore_spaces();
    int c,i= 0;
    c = getch();
    if (c == '#')
    {
        word[i++] = c;
        while ((c = getch()) != '\n') 
        {
            if (c == EOF) return EOF;
        }
    }
    else if (c == '\"')
    {
        word[i++] = c;
        while ((c = getch()) != '\"')
        {
            if (c == '\\') getch();
            if (c == EOF) return EOF;
        }
    }
    else if (c == '\'')
    {
        word[i++] = c;
        while ((c = getch()) != '\'')
        {
            if (c == '\\') getch();
            if (c == EOF) return EOF;
        }
    }
    else if (c == '/')
    {
        word[i++] = c;
        if ((c = getch()) == '/')
        {
            while ((c = getch()) != '\n') 
            {
                if (c == EOF) return EOF;
            }
        }
        else if (c == '*')
        {
            while (1)
            {
                c = getch();
                if (c == '*')
                {
                    c = getch();
                    if (c == '/') break;
                }
                if (c == EOF) return EOF;
            }
        }
        else
        {
            while (c != ' ' && c != '\t' && c != '\n')
            {
                c = getch();
                if (c == EOF) return EOF;
            }
        }
    }
    else
    {
        word[i++] = c;
        if (!(isalpha(c)))
        {
            if (c == '\\')
            {
                c = getch();
                word[i++] = c;
            }
            if (c == EOF) return EOF;
        }
        else 
        {
            c = getch();
            while (c != ' ' && c != '\t' && c!= '\n' && c != '(' && c != '[' && c != '\'' && c != '{' && c != '\"' && c != ')' && c != ']' && c != '}' && c != ';' && i < MAXWORD)
            {
                word[i++] = c;
                c = getch();
            }
            if (c == EOF)
            {
                word[i] = '\0';
                return EOF;
            }
        }
    }
    word[i] = '\0';
    return 0;
}

struct key *binsearch(char *s, struct key *tab)
{
    struct key *low = &tab[0];
    struct key *high = &tab[NKEYS -1];
    while (low < high)
    {
        struct key *mid = low + (high - low)/2; //pointer addition is illegal
        if (strcmp(s,mid->word) > 0)
        {
            low = mid + 1;
        }
        else if (strcmp(s,mid->word) < 0)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return NULL;
}

int main()
{
    char word[MAXWORD];
    struct key *p;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((p = binsearch(word, keytab)) != NULL)
            {
                p->count++;
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++)
    {
        printf("%4d %s\n",p->count, p->word);
    }
}