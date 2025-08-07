#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <math.h>    // for fmod()
#include <ctype.h>
#include <limits.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number was found
#define MAXVAL 100   // maximum depth of val stack
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack
char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor for modulo\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %c\n", type);
            break;
        }
    }
    return 0;
}

// push: push f onto value stack
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
int checktop = 0;
// getop: get next operator or numeric operand
int getop(char s[]) {
    
	int i = 0;
    	static int c;
    	if (checktop == 0)
	{
		c = getchar();
    	}
	while (c == ' ' || c == '\t')
	{
		c = getchar();
	}
	if (!isdigit(c) && c != '.')
	{
		checktop = 0;
		return c;
	}
	if (isdigit(c))
	{
		s[i++] = c;
		while (isdigit(c = getchar()))
		{
			s[i++] = c;
		}
	}
	if(c == '.')
	{
		s[i++] = c;
		while (isdigit(c = getchar()))
		{
			s[i++] = c;
		}
	}
	s[i] = '\0';
	if (c != EOF)
	{
		checktop = 1;
	}
	return NUMBER;
}
