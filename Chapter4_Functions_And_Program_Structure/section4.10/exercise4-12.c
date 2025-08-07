//recursive itoa

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int i = 0;
void itoa(int n, char s[])
{
	if (n<0)
	{
		s[i++] = '-';
		n = -n;
	}
	if (n/10)
	{
		itoa(n/10,s);
	}
	s[i++] = (n%10 + '0');
}

int main()
{
	int n = -2346;
	char s[100];
	itoa(n,s);
	s[i] = '\0';
	printf("%s\n",s);
}
