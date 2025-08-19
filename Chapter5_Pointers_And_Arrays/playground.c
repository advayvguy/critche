#include <stdio.h>
#include <ctype.h>

int main()
{
	int i = 2;
	if(i++ == 3)
	{
		printf("hello\n");
	}
	i--;
	if(++i == 3)
	{
		printf("is 3\n");
	}
}

