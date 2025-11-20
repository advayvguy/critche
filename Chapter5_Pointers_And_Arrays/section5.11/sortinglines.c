//Any pointer can be cast to void * and back again without loss of information
// so we can call qsort by casting arguments to void *

//example-
// int *a
// void *p = a; -> void is a generic pointer.
// char c = (char*)p  -> here (char *) is a cast, 

//if something returns (void *) to you, it means that it is just raw bytes from the memory
//it is ready to be interpreted in any way.

//(*comp)(void *, void*) -> comp is a pointer to a function which takes 
//two void pointers as an input

//there are two types of cast-
//data pointer cast, function pointer cast
// data pointer cast is discussed in playground 1
//function pointer cast- (int (*)(void *)) means-
//call the funtion as if its type was int and took void * as an input.
//here int (*)(void *) is a signature of the function 
//the address of the first instruction is stored in the data segment
//refer the screenshots for more clarity

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];
//we will define the functions that we will be using here

int readlines  (char *lineptr[], int nlines);
void writelines (char *lineptr[], int nlines);
int numcmp     (char *, char *);
void q_sort      (void *lineptr[], int left, int right, int (*comp)(void *, void *));

int readlines (char *lineptr[], int nlines)
{
    int c, i;
    for (i = 0; i < nlines; i++)
    {
        int j;
        for (j = 0; (c = getchar()) != '\n'; j++)
        {
            if (c == EOF) return i;
            lineptr[i][j] = c;
        }
        lineptr[i][j] = '\0';
    }
    return i;
}

void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) return;
    swap(v, left, (left + right)/2); //change pivot
    last = left;
    for (int i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i],v[left]) < 0) swap(v, ++last, i);
        swap(v,left,last);
    }
    q_sort(v,left,last-1,comp);
    q_sort(v,last+1,right,comp);
}

void writelines (char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
    {
        printf("%s",(*(lineptr + i)));
    }
}
//we dont really care about the type of values we are dealing with here, we are just 
//interchanging the positions of the raw bytes

int numcmp(char *s1, char *s2) //addressed the parameters as void so we are just casting it now
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}

void swap (void *v[], int i, int j)
{
    void *temp = v[i]; 
    v[i] = v[j];
    v[j] = temp;
}

int main (int argc, char **argv)
{
    
    int numeric = 0, nlines; //numeric 
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n') numeric = 1;
    if ((nlines = readlines(lineptr,MAXLINES)) >= 0)
    {
        q_sort (
            (void **)lineptr, //casting lineptr to void type
            0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp)
        );
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 0;
    }
}