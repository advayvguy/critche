//standard stuff here
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//defining some constants here 

#define MAXOP 100 //max size of the operand (a number with 100 digits)
#define NUMBER '0' //signal that a number was found
#define MAXVAL 100 //maximum size of the value stack (we store the numbers of the array on a stack)
#define BUFSIZE 100

int getop(char s[])
{
	int i,c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
	{
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{
		return c; //returns the operator
	}
	i = 0;
	if (isdigt(c))
	{
		while(isdigit(s[++i] = c = getch()))
		{
			;
		}
	}
	if (c == '.')//collect fractional part
	{
		while(isdigit(s[++i] = c = getch()))
	}
	s[i] = '\0';
	if (c!=EOF)
	{
		ungetch();
	}
	return NUMBER;
}
