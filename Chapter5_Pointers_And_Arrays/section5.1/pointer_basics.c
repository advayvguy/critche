#include <stdio.h>

int main()
{
	int *p;
	int x = 40;
	p = &x;
	printf("%p\n",p); //the register address the pointer is pointing to in the memory. 
	printf("%d\n",*p); //the value stored in the address the pointer is pointing to.
}
