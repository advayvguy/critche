#include <stdio.h>
#include <ctype.h>
//eleganto
int bufp = 0;
char buf[1000];

int getch(void)
{
	return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
	buf[bufp++] = c;
}

int getfloat (double *pn)
{
	int c;
	static int sign = 1;
	while (isspace(c = getch()) || c == '-' || c == '+')
	{
		if (c == '-')
		{
			sign = -1;
		}
	}
	if (!isdigit(c) && c != '-' && c != EOF && c != '+' && c != '.')
	{
		ungetch(c);
		return 0;
	}	
	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = *pn * 10 + (c-'0');
	}
	if (c == '.')
	{
		int n = 0;
		while(isdigit(c = getch()))
		{
			*pn = *pn * 10 + (c-'0');
			n++;
		}
		for (int i = 0; i<n;i++)
		{
			*pn = *pn/10;
		}
	}
	*pn *= sign;
	sign = 1;
	if (c!=EOF)
	{
		ungetch(c);
	}
	return c;
}

int main()
{
	int n =0;
	double array[1000];
	while(n  < 1000 &&  getfloat(&array[n]) != EOF)
	{
		n++;
	}
	for (int i = 0; i<n;i++)
	{
		printf("%f\n",array[i]);
	}
}
