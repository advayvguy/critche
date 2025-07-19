#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100
#define MAXBUF 100
#define NUMBER '0'
#define MAXOP 100

int bufp = 0;
char buf[MAXBUF];
int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp>=MAXBUF)
	{
		printf("buffer size exceeded\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
	{
		; //we are eating the spaces here. now s = {_} 'just a space'.
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
	{
		return c; //not a number so probably a symbol or a character we dont know about.
	}
	i = 0;
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
		{
			;
		}
	}
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
		{
			;
		}
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetch(c); //works if there is a 45+ (a symbol right after the operands)
	}
	return NUMBER;
}

int sp =0;
double val[MAXVAL];

void push(double f)
{
	if(sp<MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, cant push\n");
	}
}

double pop(void)
{
	if(sp>0)
	{
		return val[--sp];
	}
	else
	{
		printf("stack empty\n");
		return 0.0;
	}
}

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		switch(type){
		
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() + pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop()/op2);
				}
				else
				{
					printf("cant divide by 0\n");
				}
				break;
			case '\n':
				printf("\t %.8lf \n",pop());
				break;
			default:
				printf("unknown command %s\n",s);
				break;
		}
	}
}





















