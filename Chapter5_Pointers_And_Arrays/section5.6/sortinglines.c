#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//1) we need a getline function which takes the line from the input.
//2) we need a readline function that reads the line and puts it in the memory buffer
//4) we need a quicksort function that changes the pointer locations to match the lex order
//5) we need a printline function which prints the value of all the derefrences.

//firsly lets start off by defining some constants.

#define MAXLINE 5000 //5000 lines is the maximum capacity.
#define MAXLEN 1000 //1000 characters is the max capacity of the line.
#define CHUNK MAXLINE*MAXLEN //the memory chunk that is availible to work with.

//now lets define some arrays and useful pointers.

char *lineptr[MAXLINE];
char allocbuf[CHUNK];

//the getline function should return the length of the line.

int getl(char *line,int maxlen)
{
	int i,c;
	for (i = 0; ((c = getchar()) != EOF) && c != '\n';i++)
	{
		if(i > maxlen-1)
		{
			i--;
		}
		else
		{
			*(line++) = c;
		}
	}
	return i;
}

//the readline function reads the line and puts it in the memory. if the length of line is 0 then 
static char *allocp = allocbuf;

char *alloc(int len)
{
	if (allocbuf+CHUNK-allocp >= len)
	{
		allocp += len;
		return allocp - len; 
	}
	else
	{
		return 0;
	}
}

int readl(char *lineptr[])
{
	int nlines = 0,len;
	char line[MAXLEN],*p;
	while ((len = getl(line,MAXLEN)) > 0)
	{
		if (nlines > MAXLINE || (p = alloc(len+1)) == NULL)
		{
			return -1;
		}
		else
		{
			line[len] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writel(char *lineptr[],int nlines)
{
	while (nlines-- > 0)
	{
		printf("%s\n",*lineptr++);
	}
}

void swap(char **v, int i, int j)
{
	char *temp;
	temp = *(v+i);
	*(v+i) = *(v+j);
	*(v+j) = temp;
}

void q_sort(char **v, int left, int right) //char **p = lineptr means p is pointing to the first element of lineptr which is a pointer pointing to the first element of the array, eg lineptr = {"hello","world"} **p = lineptr means p is pointing to h.
{
	int i,last;
	if (left >= right)
	{
		return;
	}
	last = left;
	for (i = left+1; i<= right; i++)
	{
		if(strcmp(*(v+i),*(v+left)) < 0)
		{
			swap(v,++last,i);
		}
	}
	swap(v,left,last);
	q_sort(v,left,last-1);
	q_sort(v,last+1,right);
}

int main()
{

	int nlines = readl(lineptr);
	if (nlines < 0)
	{
		printf("error: input too big to sort\n");
	}
	else
	{
		q_sort(lineptr, 0, nlines-1);
		writel(lineptr,nlines);
	}
}
