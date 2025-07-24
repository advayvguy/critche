#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXVAL 100
#define MAXBUF 100
#define NUMBER '0'
#define MAXOP 100
#define VAR '1'

int pushedEOF = 0;
int ungetvar = 0;
double vararray[26];

int getch()
{
	//return (bufp > 0) ? buf[--bufp] : getchar();
	if (ungetvar  == 0)
	{
		return getchar();
	}
	else
	{
		int temp = ungetvar;
		ungetvar = 0;
		return temp;
	}
}
int getop(char s[])
{
	int i=0,c,hold;
	if (pushedEOF == 1)
	{
		return EOF;
	}
	while((s[0] = c = getch()) == ' ' || c == '\t')
	{
		; //we are eating the spaces here. now s = {_} 'just a space'.
	}
	s[1] = '\0';
	if (c >= 'a' && c <= 'z')
	{
		return VAR;
	}
	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}
	if (c == '-')
	{
		hold = getch();
		if (isdigit(hold))
		{
			s[++i] = c = hold;
		}
		else
		{
			ungetvar = hold;
			return c;
		}
	}
	if (isdigit(c))
	{
		while (isdigit(c = s[++i] = getch()))
		{
			;
		}
	}
	if (c == '.')
	{
		while (isdigit(c = s[++i] = getch()))
		{
			;
		}
	}
	s[i] = '\0';
	if (c != EOF)
	{
		ungetvar = c; //works if there is a 45+ (a symbol right after the operands)
	}
	else
	{
		pushedEOF = 1;
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

//void ungets(char s[])
//{
//	for(int i =0; i < strlen(s); i++)
//	{
//		ungetch(s[i]);
//	}
//}

int init[26] = {0};
int check = 0;
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		if (check == 1 && s[0] != '=')
		{
			printf("variable is uninitialized\n");
		}
		switch(type){
		
			case NUMBER:
				push(atof(s));
				break;
			case VAR:
				if (init[s[0]-'a'] == 1)
				{
					push(vararray[s[0] -'a']);
				}
				else
				{
					push(op2 = (s[0]-'a')*1.0);
					check = 1;
				}
				break;
			case '=':
				if (check == 1)
				{
					op2 = pop();
					vararray[(int)op2] = pop();
					init[(int)op2] = 1;
					check = 0;
				}
				else 
				{
					printf("error: you cant initialize a number to a number or existing variable\n");
				}
				break;				
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
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
			case '%':
				int divisor = pop();
				int divident = pop();
				int quotient;
				for (quotient = 0; divisor*quotient <= divident; quotient++)
				{
					;
				}
				push(divident-(divisor*(quotient-1)));
				break;
			case 'S':
				push(sin(pop()));
				break;
			case 'E':
				push(exp(pop()));
				break;
			case 'P':
				op2 = pop();
				push(pow(pop(),op2));
				break;
			case 'R':
				printf("\t %.8lf \n",val[sp-1]);
				break;
			case 'D':
				val[sp++] = val[sp-1];
				break;
			case 'F':
				op2 = val[sp-1];
				val[sp-1] = val[sp-2];
				val[sp-2] = op2;	
				break;
			case 'C':
				sp = 0;
				for (int i = 0; i < 26; i++)
				{
					init[i] = 0;
				}
				break;
			case '\n':
				if (sp>1)
				{
					printf("error: operator/s missing\n");
				}
				else
				{
					printf("\t %.8lf \n",pop());
				}
				sp = 0;
				break;	
			default:
				printf("unknown command %s\n",s);
				break;
		}
	}
}





















