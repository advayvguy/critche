#include <stdio.h>
#include <ctype.h>
//elegento
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

int getint (int *pn)
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
	if (!isdigit(c) && c != '-' && c != EOF && c != '+')
	{
		ungetch(c);
		return 0;
	}	
	for (*pn = 0; isdigit(c); c = getch())
	{
		*pn = *pn * 10 + (c-'0');
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
	int n = 0, array[1000],check = 1;
	while(n  < 1000 && (check = getint(&array[n]) != EOF))
	{
		if(check == 0)
		{
			;
		}
		else
		{
			n++;
		}
	}
	for (int i = 0; i<n;i++)
	{
		printf("\n%d\n",array[i]);
	}

}
