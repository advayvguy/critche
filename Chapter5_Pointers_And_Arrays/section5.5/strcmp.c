//using pointers, lexographically compare two character arrays.
#include <stdio.h>

int str_cmp(char *s, char *t)
{
	while (*s == *t)
	{
		if (*s == '\0')
		{
			return 0;
			
		}
	}
	return *s - *t;
}

int main()
{
	char s[] = "hello";
	char t[] = "helao";
	int lex = str_cmp(s,t);
	printf("%d\n",lex);
}
