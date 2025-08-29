//string copy using pointers.

#include <stdio.h>

void str_cpy(char *s, char *t)
{
	while((*t++ = *s++) != '\0') //really just *(t++) instead of (*t++)
		;
}

int main()
{
	char t[1000];
	str_cpy("hello",t);
	printf("%s\n",t);
}
