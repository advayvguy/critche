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

int binsearch(char *word, int low, int high)
{
    int cond,mid;
    while (low <= high)
    {
        mid = (low + high)/2;
        cond = strcmp(word, keytab[mid].word);
        if (cond > 0) low = mid + 1;
        else if (cond < 0) high = mid - 1;
        else return mid;
    }
    return -1;
}

int main()
{
    int n;
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0]))
        {
            if ((n = binsearch(word,0,NKEYS-1)) >= 0)
            {
                keytab[n].count++;
            }
        }
        unget = '\0';
    }
    for (int i = 0; i < NKEYS; i++)
    {
        if (keytab[i].count > 0) printf("%4d %s\n",keytab[i].count, keytab[i].word);
    }
}