#include <stdio.h>
#include <string.h>
//the null terminator is not counted by strlen

void str_cat(char *b,char *t)
{
	int i,j = 0;
	b = b + strlen(b);
	for (j = 0; *(t+j) != '\0'; j++)
	{
		*(b+j) = *(t+j);
	}
	*(b+j) = '\0';
}

int main()
{
	//you cant leave s_base[] just like that becuase then it would take the array length to be the one you provided. 
	char s_base[50] = "Hello ";
	char s_tail[50] = "World";
	str_cat(s_base,s_tail);
	printf("%s\n",s_base);
}
