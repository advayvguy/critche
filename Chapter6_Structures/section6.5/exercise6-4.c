#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXWORD 100

struct tnode 
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct elements
{
    char *word;
    int count;
};

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *salloc(char *word)
{
    char *p = (char *)(malloc(strlen(word) + 1));
    if (p != NULL)
    {
        strcpy (p,word);
    }
    return p;     
}

struct tnode *addtree(struct tnode *p,char *s)
{
    int cond;
    if (p == NULL)
    {
        p = talloc();
        p->word = salloc(s);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(s,p->word)) == 0) p->count++;
    else if (cond > 0) p->right = addtree(p->right,s);
    else if (cond < 0) p->left = addtree(p->left, s);
    return p;
}

int treecount(struct tnode *p)
{
    if (p != NULL)
    {
        return 1 + treecount(p->left) + treecount(p->right);
    }
    else return 0;
}

void tadd(struct tnode *p, struct elements *arr,int *arrp)
{
    if (p != NULL)
    {
        tadd(p->left, arr,arrp);
        arr[*arrp].word = p->word;
        arr[*arrp].count = p->count;
        (*arrp)++;
        tadd(p->right,arr,arrp);
    }
}

void swap (struct elements *a, struct elements *b)
{
    int tempc = a->count;
    char *temps = a->word;
    a->word = b->word;
    b->word = temps;
    a->count = b->count;
    b->count = tempc;
}

void q_sort(struct elements *a, int left, int right)
{
    if (left >= right) return;
    int pivot = a[left].count;
    int p1 = left + 1;
    int p2 = right;
    while (p1 <= p2)
    {
        if (a[p2].count <= pivot) p2--;
        else if (a[p1].count >= pivot) p1++;
        else swap(&a[p1], &a[p2]);
    } 
    swap (&a[left], &a[p2]);
    q_sort (a, left, p2-1);
    q_sort (a, p2+1, right);
}

int getword(char *word, int max)
{
    int c,i;
    while ((c = getchar()) == ' ' || c == '\t');
    for (i = 0; isalpha(c) && i < max-1; i++)
    {
        word[i] = c;
        c = getchar();
    }
    if (c == EOF) return EOF;
    word[i] = '\0';
    if (strlen(word) > 0) return 0;
    return 1;
}

int main()
{
    char word[MAXWORD];
    int c;
    struct tnode *root = NULL;
    while ((c = getword(word, MAXWORD)) != EOF)
    {
        if (c == 0) root = addtree(root, word);
    }
    int count = treecount(root);
    struct elements *array = (struct elements *)malloc(sizeof(struct elements)*count);
    int index = 0;
    tadd(root,array,&index);
    q_sort(array,0,count-1);
    for (int j = 0; j < 50; j++) printf("-");
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ",array[i].count);
        printf("%s\n",array[i].word);
    }
}