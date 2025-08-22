#include <stdio.h>
#include <ctype.h>

int getint(int *p)
{
	int c, sign;
	while(isspace(c = getchar()))
	;
	if (c == EOF)
	{
		return c;
	}
	if (!isdigit(c) && c != '+' && c != '-')
	{
		return 0;
	}
	sign = (c == '-') ? -1:1;
	if (c == '-' || c == '+')
	{
		c = getchar();
	}
	if (isdigit(c) && c != EOF)
	{
		*p = c-'0';
		c = getchar();
	}
	while (isdigit(c))
	{
		*p = *p * 10 + (c - '0');
		c = getchar();
	}
	*p *= sign;
	return c;
}


int main()
{
	int n, array[1000];
	for (n = 0; n<1000 && getint(&array[n]) != EOF; n++)
	;
	for (int i = 0; i<n;i++)
	{
		printf("\n%d\n",array[i]);
	}
}
