#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define HASHSIZE 101

struct nlist 
{
    struct nlist *next;
    char *name; //defined name
    char *defn; //replacement text (value associated with name)
};

static struct nlist *hashtab[HASHSIZE];

unsigned int hash(char *s)
{
    int hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31*hashval;
    }
    return hashval%HASHSIZE;
}

struct nlist *lookup(char *s)
{
    int hashval = hash(s);
    struct nlist *np;
    for (np = hashtab[hashval]; np != NULL ; np = np->next)
    {
        if (strcmp(np->name,s) == 0) return np;
    }
    return NULL;
}

struct nlist *install(char *id, char *def)
{
    struct nlist *node;
    if ((node = lookup(id)) == NULL)
    {
        node = (struct nlist *)malloc(sizeof(struct nlist));
        if (node == NULL || (node->name = strdup(id)) == NULL) return NULL;
        unsigned int hashval = hash(id);
        node->next = hashtab[hashval];
        hashtab[hashval] = node;
    }
    else free(node->defn);
    if ((node->defn = strdup(def)) == NULL) return NULL;
    return node;
}

int undef(char *id)
{
    unsigned int hashval = hash(id);
    struct nlist *node;
    struct nlist *prevnode = NULL;
    for(node = hashtab[hashval]; node != NULL; node = node->next)
    {
        if (strcmp(node->name, id) == 0)
        {
            if (prevnode == NULL) hashtab[hashval] = node->next;
            else prevnode->next = node->next;
            free(node->name);
            free(node->defn);
            free(node);
            return 0;
        }
        prevnode = node;
    }
    return -1;
}

//test
int main()
{
    // Build a 3-node chain in bucket 74
    install("aa","100");   // tail
    install("di","200");   // middle
    install("gq","300");   // head

    printf("Initial chain:\n");
    for (struct nlist *p = hashtab[74]; p; p = p->next)
        printf("%s %s\n", p->name, p->defn);

    // 1. Delete head
    printf("\nDelete gq (head):\n");
    undef("gq");
    for (struct nlist *p = hashtab[74]; p; p = p->next)
        printf("%s %s\n", p->name, p->defn);

    // 2. Delete middle (which is now 'di')
    printf("\nDelete di (middle):\n");
    undef("di");
    for (struct nlist *p = hashtab[74]; p; p = p->next)
        printf("%s %s\n", p->name, p->defn);

    // 3. Delete tail (now 'aa', the last one)
    printf("\nDelete aa (tail):\n");
    undef("aa");
    for (struct nlist *p = hashtab[74]; p; p = p->next)
        printf("%s %s\n", p->name, p->defn);

    // 4. Delete from empty bucket
    printf("\nDelete non-existent key:\n");
    printf("undef(xxx) = %d\n", undef("xxx"));

    // 5. Re-insert to check that bucket still works
    printf("\nReinsert test:\n");
    install("gq","900");
    install("aa","800");
    for (struct nlist *p = hashtab[74]; p; p = p->next)
        printf("%s %s\n", p->name, p->defn);

    return 0;
}
