/*
-----------------------------------Q_SORT_ON_STEROIDS--------------------------------------
this program takes 4 flags and is capable of sorting within fields in the given input
(for an MxN matrix input, sorting is performed on each of the N coloumns)
N_flag- numeric sorting
R_flag- descending order
F-flag- we ignore cases while sorting lexographically
D_flag- we sort in dictionary order, meaning that comparisions are only made to letters and numbers
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define CAP 5000000

int N_FLAG = 0;
int R_FLAG = 0;
int F_FLAG = 0;
int D_FLAG = 0;

char *lineptr[MAXLINES]; //character pointer array
char ALLOCBUF[CAP]; //static memory
int allocp = 0;

int readlines(char **lineptr, int nlines, int *numfields)
{
    int i,c,check = 0, pushback = '\0';
    for (i = 0; i < nlines; i++)
    {
        int initial = allocp;
	while (allocp < CAP)
        {
            c = (pushback != '\0') ? pushback : getchar();
	    pushback = '\0';
            if (c == EOF) 
	    {
	    	    return i;
	    }
	    if (c == '\n' || c == ' ' || c == '\t')
	    {

		    if (check == 0) (*numfields)++;
		    if (c == ' ' || c == '\t')
		    {
			    while ((c = getchar())==' ' || c == '\t');
			    pushback = c;
		    }
		    if (c == '\n') check = 1;
		    break;
	    } 
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

void writelines(char **s, int nlines, int numfields)
{
    for (int i = 0; i < (nlines/numfields); i++)
    {
	    for (int j = 0; j < numfields; j++) printf("%s\t",s[i + (nlines/numfields)*j]);
	    printf("\n");
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
    char *shifted_lineptr[MAXLINES];	
    int nlines, numfields = 0;
    for (int i = 1; i < argc; i++)
    {
	    for (int j = 1; argv[i][0] == '-' && argv[i][j] != '\0'; j++)
	    {
		    if ((argv[i][j]) == 'n') N_FLAG = 1;
		    if ((argv[i][j]) == 'r') R_FLAG = 1;
		    if ((argv[i][j]) == 'f') F_FLAG = 1;
		    if ((argv[i][j]) == 'd') D_FLAG = 1;	
	    }
    }
    int (*fptr)(const char *, const char *);
    if (N_FLAG == 1) fptr = numcmp;
    else if (D_FLAG == 1) fptr = dcmp;
    else if (F_FLAG == 0) fptr = strcmp;
    else if (F_FLAG == 1) fptr = str_cmp_nocase;
    if ((nlines = readlines(lineptr, MAXLINES, &numfields)) >= 0)
    {
	int k = 0;
	for (int i = 0; i < numfields; i++)
	{
		for (int j = i; j < nlines; j+=numfields)
		{
			shifted_lineptr[k++] = lineptr[j]; 
		}
	}
    	int rows = nlines/numfields;
    	if (nlines % numfields != 0)
    	{
    		printf("inconsistant number of fields\n");
		return 1;
        }
    	for (int i = 0; i < numfields; i++)
    	{
		q_sort((void **)shifted_lineptr, R_FLAG,
        	rows*i, rows*(i+1)-1, fptr);
    	}

	//q_sort
        //(
            //(void **)lineptr, //casting lineptr to void pointer array
            //R_FLAG,0,
            //nlines-1,
            //fptr
	    //(int (*)(void *, void *))(n ? numcmp : strcmp) //function cast
        //);
   	for (int i = 0; i < 50; i++) printf("%c",'-');
	printf("\n");
   	writelines(shifted_lineptr, nlines, numfields); 
   	for (int i = 0; i < 50; i++) printf("%c",'-');
	printf("\n");
	return 0;
    }
    else 
    {
        printf("input is too big to sort\n");
        return 1; //just a practise i guess
    }
}
