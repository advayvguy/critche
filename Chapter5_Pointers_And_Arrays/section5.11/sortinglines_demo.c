#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define CAP 5000000

char *lineptr[MAXLINES]; //character pointer array
char ALLOCBUF[CAP]; //static memory
int allocp = 0;

int readlines(char **lineptr, int nlines)
{
    int i,c;
    for (i = 0; i < nlines; i++)
    {
        int initial = allocp;
        while (allocp < CAP)
        {
            c = getchar();
            if (c == EOF) return i;
            if (c == '\n') break;
            ALLOCBUF[allocp++] = c;
        }
        if (allocp >= CAP) return -1;
        if (allocp != initial)
        {
            ALLOCBUF[allocp++] = '\0';
            lineptr[i] = ALLOCBUF + initial;
        }
        else i--;
    }
    return i;
}

void writelines(char **lineptr, int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n",lineptr[i]);
    }
}

int numcmp(char *s1, char *s2)
{
    float f1 = atof(s1);
    float f2 = atof(s2);
    return (f1 > f2) - (f2 > f1);
}

void swap(char **v, int i, int j) //independent of the cast
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//need to work on my algorithm even here
void q_sort
(
    void **v, //this is just a generalization here, nothing significant yet
    int left,
    int right,
    int (*comp)(void *, void *)
)
{
    
}

int main(int argc, char **argv)
{
    int nlines, n = 0;
    if (argc > 1 && strcmp(argv[1], "-n") == 0) n = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        q_sort
        (
            (void **)lineptr, //casting lineptr to void pointer array
            0,
            nlines-1,
            (int (*)(void *, void *))(n ? numcmp : strcmp) //function cast
        );
        writelines(lineptr, nlines);
        return 0;
    }
    else 
    {
        printf("input too big to sort\n");
        return 1; //just a practise i guess
    }
}