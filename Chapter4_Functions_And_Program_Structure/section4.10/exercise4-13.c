//reversing a string using recursion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

void rev(char s[],char c[],int first)
{
	if (first < strlen(s)-1)
	{
		rev(s,c,first+1);
	}
	c[i++] = s[first];
}

//another method of solving this without using external int and an empty character array.
//void rev(char s[],int first,int last)
//{
//	if (first >= last)
//	{
//		return;
//	}
//	char temp = s[first];
//	s[first] = s[last];
//	s[last] = s[temp];
//	rev(s,first+1,last-1);
//}

int main()
{
	char c[100];
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	int first = 0;
	rev(s,c,first);
	c[i] = '\0';
	printf("%s\n",c);
}
