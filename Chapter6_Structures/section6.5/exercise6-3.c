#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORD 100

char *noisewords[] = {
    "the",
    "and",
    "a",
    "an",
    "in",
    "of",
    "to",
    "is",
    "for",
    "on",
    "with",
    NULL
};


struct tnode 
{
    int *arr;
    int arrp;
    char *word;
    struct tnode *left;
    struct tnode *right;
};



char *salloc(char *word)
{
    char *p = (char *)(malloc(strlen(word) + 1));
    if (p != NULL)
    {
        strcpy (p,word);
    }
    return p;
}

struct tnode *talloc()
{
    return (struct tnode *)(malloc(sizeof(struct tnode)));
}

int *aalloc()
{
    return malloc(sizeof(int));
}

int *reaalloc(int *arr, int size)
{
    int *temp;
    if ((temp = (int *)realloc(arr, sizeof(int)*size)) != NULL) return temp;
    else return arr;
}

struct tnode *addtree(struct tnode *p, char *word, int lno)
{
    int cond;
    if (p == NULL)
    {
        p = talloc();
        p->word = salloc(word);
        p->arr = aalloc();
        p->arr[0] = lno;
        p->arrp = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(word,p->word)) == 0) 
    {
        if (p->arr[p->arrp -1] != lno)
        {
            p->arr = reaalloc(p->arr, p->arrp);
            p->arr[p->arrp] = lno;
            p->arrp++;
        }
    }
    else if (cond < 0) p->left = addtree(p->left, word, lno);
    else if (cond > 0) p->right = addtree(p->right, word, lno);
    return p;
}

void printtree(struct tnode *p)
{
    static int num = 1;
    if (p != NULL)
    {
        printtree(p->left);
        printf("%d) %s- ", num++, p->word);
        for (int i = 0; i < p->arrp; i++)
        {
            printf("%d ",p->arr[i]);
        }
        printf("\n");
        printtree(p->right);
    }
}

int check_noise(char *dest, char *source)
{
    for (int i = 0; noisewords[i] != NULL; i++)
    {
        if (strcmp(noisewords[i], source) == 0) return -1;
    }
    strcpy(dest,source);
    return 0;
}

int getword(char *word, int max)
{
    int c,check;
    char source[MAXWORD];
    while ((c = getchar()) == ' ' || c == '\t') ;
    int i = 0;
    for (i = 0; i < max-1 && isalpha(c); i++)
    {
        source[i] = c;
        c = getchar();
    }
    source[i] = '\0';
    if (c == EOF) return EOF;
    if (c == '\n')
    {
        if ((check_noise(word,source) == -1) || strlen(source) == 0) return 3;
        else return 2;
    }
    else
    {
        if ((check_noise(word,source) == -1) || strlen(source) == 0) return 1;
        else return 0;
    }
}

int main()
{
    int lno = 1,c;
    struct tnode *root = NULL;
    char word[MAXWORD];
    while ((c = getword(word, MAXWORD)) != EOF)
    {
        if (c == 2 || c == 0) root = addtree(root,word,lno);
        if (c == 3 || c == 2) lno++;
    }
    printtree(root);
}