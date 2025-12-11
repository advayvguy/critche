#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

//malloc returns NULL if no space is available (from the space allocated for the program)
struct tnode *talloc()
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdwp(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
    {
        strcpy(p,s);
    }
    return p;
}

//add node with w at or below p
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL)
    {
        p = talloc();
        p->word = strdwp(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w,p->word)) == 0) p->count++;
    else if (cond < 0) p->left = addtree(p->left, w);
    else p->right = addtree(p->right, w);
    return p;
}

//pretty neat ngl
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n",p->count, p->word);
        treeprint(p->right);
    }
}

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
            while (c != ' ' && c != '\t' && c!= '\n' && 
                   c != '(' && c != '['  && c != '\'' && 
                   c != '{' && c != '\"' && c != ')' && 
                   c != ']' && c != '}'  && c != ';' && 
                   i < MAXWORD)
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

int main()
{
    struct tnode *root = NULL;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
    {
        if (isalpha(word[0])) root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}