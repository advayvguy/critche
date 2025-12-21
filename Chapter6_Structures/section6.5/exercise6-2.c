#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORD 100

enum checks {END,VALID,SKIP};

char *vars[] = 
{
    "int", "float", "double", "char", "return", "if", "else", "for", "while",
    "do", "switch", "case", "break", "continue", "goto", "sizeof", "struct",
    "union", "typedef", "enum", "const", "volatile", "static", "extern",
    "register", "auto", "void", "default", "signed", "unsigned",
    "true", "false", "NULL"
};

int checkvars(char *s)
{
    for (int i =0; i<33; i++)
    {
        if (strcmp(s,vars[i]) == 0) return SKIP;
    }
    return VALID;
}

int getword(int first, char *word)
{
    int c;
    static char key[MAXWORD];
    static int check = 0;
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n') ;
    if (c == '/')
    {
        c = getchar();
        if (c == '/')
        {
            while ((c = getchar()) != '\n')
            {
                if (c == EOF) return END;
            }
        }
        else if (c == '*')
        {
            while (1)
            {
                c = getchar();
                if (c == '*')
                {
                    c = getchar();
                    if (c == '/') break;
                }
                if (c == EOF) return END;
            }
        }
        return SKIP;
    }
    if (c == '\"')
    {
        while ((c = getchar()) != '\"')
        {
            if (c == EOF) return END;
        }
        return SKIP;
    }
    if (c == '\'')
    {
        while ((c = getchar()) != '\'')
        {
            if (c == EOF) return END;
        }
        return SKIP;
    }
    if (c == '#')
    {
        while ((c = getchar())!= '\n')
        {
            if (c == EOF) return END;
        }
        return SKIP;
    }
    if (check == 0)
    {
        int i,j;
        for (j = 0; (isalpha(c) || isdigit(c) || c == '_') && j < first; j++)
        {
            if (c == EOF) return END;
            key[j] = c;
            c = getchar();
        }
        key[j] = '\0';
        if (checkvars(key) == SKIP) return SKIP;
        strcpy(word, key);
        for (i = j; (c != EOF) && (isalpha(c) || isdigit(c) || c == '_') && i < MAXWORD; i++)
        {
            word[i] = c;
            c = getchar();
        }
        word[i] = '\0';
        if (c == EOF) return END;
        if (checkvars(word) == SKIP) return SKIP;
        check = 1;
        return VALID;
    }
    else
    {
        int i;
        for (i = 0; (c != EOF) && (isalpha(c) || isdigit(c) || c == '_') && i < MAXWORD; i++)
        {
            word[i] = c;
            c = getchar();
        }
        word[i] = '\0';
        if (c == EOF) return END;
        if (checkvars(word) == SKIP) return SKIP;
        if (strncmp(word, key, first) == 0) return VALID;
        else return SKIP;
    }
}

struct tnode
{
    char *s;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdwp(char *s)
{
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL) strcpy(p,s);
    return p;
}

struct tnode *addtree(struct tnode *p, char *word)
{
    int cond;
    if (p == NULL)
    {
        p = talloc();
        p->s = strdwp(word);
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(word,p->s)) > 0) p->right = addtree(p->right, word);
    else if (cond < 0) p->left = addtree(p->left, word);
    return p;
}

void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%s\n",p->s);
        treeprint(p->right);
    }
}

int main(int argc, char **argv)
{
    char word[MAXWORD];
    int first = 6,c;
    if (argc > 1 && argv[1][0] == '-') first = atoi(argv[1] + 1);
    struct tnode *root = NULL;
    while((c = getword(first,word)) != END)
    {
        if (c == VALID) root = addtree(root, word); 
    }
    for (int i = 0; i < 50; i++) printf("-");
    printf("\n");
    treeprint(root);
}