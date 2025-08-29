//program to make a very simple stack based (last in first out) storage allocater.
//really a very poor sort of a memory.

#include <stdio.h>

const int ALLOCSIZE =  1000;
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* points to the next free position */

char *alloc(int n)
{
	if (allocbuf+ALLOCSIZE-allocp >= n)
	{
		allocp += n;
		return allocp - n; /* return old pointer, indicates the start of the new data */
	}
	else
	{
		return 0; /* just bounce back the data you gave me or in other words indicate an invalid instruction */
		//pointers and integers are not interchangable. But zero is an excaption as no memory unit is addressed as a 0.
		//or we could write ->return NULL; <- its a signal.
	}
}

void afree(char *p)
{
	if (p >= allocbuf && p <= allocbuf + ALLOCSIZE)
	{
		allocp = p;
	}
}
