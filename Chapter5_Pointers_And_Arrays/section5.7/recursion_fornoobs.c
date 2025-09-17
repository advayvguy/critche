//dcomputing the value of e 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}
}

double count(int n)
{
	if (n == 0)
	{
		return 1.0;
	}
	else 
	{
		return 1.0/fact(n) + count(n-1);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	double j = count(n);
	printf("%0.51lf\n",j);
}

