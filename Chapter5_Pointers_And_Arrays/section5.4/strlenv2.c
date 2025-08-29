#include <stdio.h>

int main()
{
	char *p;
	char s[] = "hello";
	p = s;
	while(*p != '\0')
	{
		p++;
	}
	printf("%p\n",p-s);
}
