#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define HASHSIZE 101
#define MAXWORD 100
#define BUFFSIZE 100

enum NUMS {END, SKIP, VALID, TOKEN};

struct nlist
{
    char *name;
    char *defn;
    struct nlist *next;
};

struct nlist *hashtab[HASHSIZE];

/*unget and get buffer*/
int allocp = 0;
int ungetb[BUFFSIZE];

int getch()
{
    if(allocp == 0) return getchar();
    else {allocp--; return ungetb[allocp];}
}

void unget(int c)
{
    if (allocp == BUFFSIZE-1) printf("max buffer capacity reached\n");
    else ungetb[allocp++] = c;
}

/*
getword function-
    objectives-
        1)should return END if EOF is encountered
        2)should return VALID if its an entry to be added in the hashtab
        3)should return TOKEN if the entry has to be checked
        4)should eat up the #define ... line
        5)should be modular and well laid out, use helper functions.
*/

int eatspaces()
{
    int c;
    while((c = getch()) == ' ' || c == '\t' || c == '\n') printf("%c",c);
    if (c != EOF) {unget(c); return VALID;}
    else return END;
}

int printmisc()
{
    int c = getch();
    if (c == '/')
    {
        printf("/");
        c = getch();
        if (c == '/')
        {
            printf("/");
            while ((c = getch()) != '\n' && c != EOF)
            {
                printf("%c",c);
            }
            if (c != EOF) printf("\n");
        }
        else if (c == '*')
        {
            printf("*");
            while (c != EOF)
            {
                c = getch();
                if (c == '*')
                {
                    printf("*");
                    c = getch();
                    if (c == '/')
                    {
                        printf("/");
                        break;
                    }
                }
                else printf("%c",c);
            }
        }
        else unget(c);
    }
    else if (c == '\'')
    {
        printf("\'");
        while((c = getch()) != '\'' && c != EOF)
        {
            printf("%c",c);
            if (c == '\\') {c = getch(); printf("%c",c);}
        }
        if (c != EOF) printf("\'");
    }
    else if (c == '\"')
    {
        printf("\"");
        while((c = getch()) != '\"' && c != EOF)
        {
            printf("%c",c);
            if (c == '\\') {c = getch(); printf("%c",c);}
        }
        if (c != EOF) printf("\"");
    }
    else {unget(c); return VALID;}
    if (c == EOF) return END;
    else return SKIP;
}

int checkentry(char *word, char *def)
{
    int c = getch();
    if (c == '#')
    {
        int i = 0;
        char check[MAXWORD];
        while ((c = getch()) != ' ' && c != '\t' && c != '\n' && c != EOF && i <MAXWORD-1)
        {
            check[i++] = c;
        }
        check[i] = '\0';
        if (c == EOF) return END;
        if (strcmp("define",check) != 0) {printf("#%s",check); unget(c); return SKIP;}
        i = 0;
        if (eatspaces() == END) return END;
        while ((c = getch()) != ' ' && c != '\t' && c != EOF && i <MAXWORD-1)
        {
            word[i++] = c;
        }
        word[i] = '\0';
        if (eatspaces() == END) return END;
        i = 0;
        while ((c = getch()) != '\n' && c != EOF && i <MAXWORD-1)
        {
            def[i++] = c;
        }
        if (c == EOF) return END;
        def[i] = '\0';
        return VALID;
    }
    else
    {
        unget(c);
        return TOKEN;
    }
}

int printsymb()
{
    int c = getch();
    if (!isalpha(c) && !isdigit(c) && c != '_') {printf("%c",c); return SKIP;}
    else if (c == EOF) return END;
    else {unget(c); return VALID;}
}

int getword(char *word, char *def)
{
    int check;
    //print spaces-
    if (eatspaces() == END) return END;

    //print comments, stuff inside quotations
    if ((check = printmisc()) == END) return END;
    else if (check == SKIP) return SKIP;

    //print spaces 
    if (eatspaces() == END) return END;

    //if define preprocessor is encountered we return the word and the def
    if ((check = checkentry(word, def)) == END) return END;
    else if (check == VALID) return VALID;
    else if (check == SKIP) return SKIP;

    //print spaces
    if (eatspaces() == END) return END;

    //print other symbols
    if ((check = printsymb()) == END) return END;
    else if (check == SKIP) return SKIP;

    //print spaces
    if (eatspaces() == END) return END;

    //return TOKEN
    int c = getch(), i = 0;
    while(c != EOF && (isdigit(c) || c == '_' || isalpha(c) && i < MAXWORD-1))
    {
        word[i++] = c;
        c = getch();
    }
    if (c == EOF) return END;
    else {word[i] = '\0'; unget(c); return TOKEN;}
}

/*hashing function*/
unsigned int hash(char *s)
{
    unsigned int hashval = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        hashval = s[i] + 31*hashval;
    }
    return hashval%HASHSIZE;
}

/*installs stuff into the hashtab*/
struct nlist *install(char *id, char *def)
{
    struct nlist *i;
    unsigned int hashval = hash(id);
    for (i = hashtab[hashval]; i != NULL; i = i->next)
    {
        //if an entry is found
        if(strcmp(i->name,id) == 0)
        {
            char *s;
            if ((s = strdup(def)) == NULL)
            {
                printf("no space for new definition\n");
            }
            else
            {
                free(i->defn);
                i->defn = s;
            }
            return i;
        }
    }
    //if no entry is found
    if ((i = malloc(sizeof *i)) == NULL) return NULL;
    if ((i->name = strdup(id)) == NULL) {free(i); return NULL;}
    if ((i->defn = strdup(def)) == NULL) {free(i->name); free(i); return NULL;}
    i->next = hashtab[hashval];
    hashtab[hashval] = i;
    return i;
}

/*prints the final hashtable*/
void printstate()
{
    for(int i = 0; i < HASHSIZE; i++)
    {
        if (hashtab[i] != NULL)
        {
            for (int j = 0; j < 75; j++) printf("-");
            printf("\n");
            printf("Bucket %d: %p -> ", i, hashtab[i]);
            for(struct nlist *np = hashtab[i]; np != NULL; np = np->next)
            {
                printf("[%s|%s|%p] -> ",np->name,np->defn,np->next);
            }
            printf("NULL\n");
        }
    }
    for (int j = 0; j < 75; j++) printf("-");
    printf("\n");
}

/*looks up whether the entry is present or not and returns the pointer if it is*/
struct nlist *lookup(char *s)
{
    unsigned int hashval = hash(s);
    for (struct nlist *node = hashtab[hashval]; node != NULL; node = node->next)
    {
        if(strcmp(node->name, s) == 0) return node;
    }
    return NULL;
}

int main()
{
    char word[MAXWORD];
    char def[MAXWORD];
    int c;
    while ((c = getword(word, def)) != END)
    {
        if (c == VALID)
        {
            if (install(word,def) == NULL) printf("no space left");
        }
        if (c == TOKEN)
        {
            struct nlist *p = lookup(word);
            if (p == NULL) printf("%s",word);
            else printf("%s",p->defn);
        }
    }
    printf("\n");
    for (int i = 0; i < 75; i++) printf("-");
    printf("\n");
    printf("hashtab state-\n");
    printstate();
}
