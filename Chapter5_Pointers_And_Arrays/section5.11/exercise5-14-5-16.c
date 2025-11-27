#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define CAP 5000000

int N_FLAG = 0;
int R_FLAG = 0;
int F_FLAG = 0;
int D_FLAG = 0;
int E_FLAG = 0;

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

int str_cmp_nocase(const char *s1, const char *s2)
{
	int c1, c2;
	for (int i = 0;;i++)
	{
		c1 = s1[i]; 
		c2 = s2[i];
		if ((c1 == '\0') && (c2 == '\0')) return 0;
		else if (c1 == '\0') return -1;
		else if (c2 == '\0') return 1;
		if (s1[i] >= 'a' && s1[i] <= 'z') c1 = s1[i] - 'a' + 'A';
		if (s2[i] >= 'a' && s2[i] <= 'z') c2 = s2[i] - 'a' + 'A';
		if (c1 > c2) return 1;
		else if (c1 < c2) return -1;
	}
}

int numcmp(const char *s1, const char *s2)
{
    float f1 = atof(s1);
    float f2 = atof(s2);
    return (f1 > f2) - (f2 > f1);
}

//inelagant, need to find a better solution
int dcmp(const char *s1, const char *s2)
{
	char s11[1000];
	char s22[1000];
	int j = 0;
	for (int i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == ' ' || (s1[i] <= '9' && s1[i] >= '0') || (s1[i] <= 'z' && s1[i] >= 'a') || (s1[i] >= 'A' && s1[i] <= 'Z'))
		{
			s11[j++] = s1[i];
		}
	}
	s11[j] = '\0';
	j = 0;
	for (int i = 0; s2[i] != '\0'; i++)
	{
		if (s2[i] == ' ' || (s2[i] <= '9' && s2[i] >= '0') || (s2[i] <= 'z' && s2[i] >= 'a') || (s2[i] >= 'A' && s2[i] <= 'Z'))
		{
			s22[j++] = s2[i];
		}
	}
	s22[j] = '\0';
	if (F_FLAG == 0) return strcmp(s11,s22);
	else return str_cmp_nocase(s11,s22);
}

void swap(void **v, int i, int j) //independent of the cast
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


//need to work on my algorithm even here
void q_sort
(
    void **v, //this is just a generalization here, nothing significant yet
    int check,
    int left,
    int right,
    int (*comp)(const char *, const char *)
)
{
	if (left >= right) return;
	void *pivot = v[left];
	int p1 = left + 1;
	int p2 = right;
	while (p2 >= p1)
	{
		if ((*comp)(v[p2], pivot) >= 0 && check == 0) p2--;
		else if ((*comp)(v[p2],pivot) <= 0 && check == 1) p2--;
		else if ((*comp)(pivot, v[p1]) >= 0 && check == 0) p1++;
		else if ((*comp)(pivot,v[p1]) <= 0 && check == 1) p1++;
		else swap(v, p1, p2);
	}
	swap(v, left, p2);
	q_sort(v, check, left, p2-1, comp);
	q_sort(v, check,  p2+1, right, comp);
}

int main(int argc, char **argv)
{
    int nlines;
    for (int i = 1; i < argc; i++)
    {
	    for (int j = 1; argv[i][0] == '-' && argv[i][j] != '\0'; j++)
	    {
		    if ((argv[i][j]) == 'n') N_FLAG = 1;
		    if ((argv[i][j]) == 'r') R_FLAG = 1;
		    if ((argv[i][j]) == 'f') F_FLAG = 1;
		    if ((argv[i][j]) == 'd') D_FLAG = 1;	
	    	    if ((argv[i][j]) == 'e') E_FLAG = 1;
	    }
    }
    int (*fptr)(const char *, const char *);
    if (N_FLAG == 1) fptr = numcmp;
    else if (D_FLAG == 1) fptr = dcmp;
    else if (F_FLAG == 0) fptr = strcmp;
    else if (F_FLAG == 1) fptr = str_cmp_nocase;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        q_sort
        (
            (void **)lineptr, //casting lineptr to void pointer array
            R_FLAG,0,
            nlines-1,
            fptr
	    //(int (*)(void *, void *))(n ? numcmp : strcmp) //function cast
        );
   	for (int i = 0; i < 30; i++) printf("%c",'-');
	printf("\n");
   	writelines(lineptr, nlines);
        return 0;
    }
    else 
    {
        printf("input is too big to sort\n");
        return 1; //just a practise i guess
    }
}
