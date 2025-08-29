#include <stdio.h>

int main()
{
	int x = 42;
	int y = 5;
	int *p;
	p = &x;
	int *q = &y;
	printf("%p %p %ld\n",p,q,p-q);
}
