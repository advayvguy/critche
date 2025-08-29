#include <stdio.h>

int main()
{
	char s[] = "hello";
	char *p; //p is a variable that can hold the address of a character.i
	p = &s[0]; //give p the address of the character s[0].
	printf("%p\n",p);
	printf("%p\n",p+1);

}
