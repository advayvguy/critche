#include <stdio.h>
#include <string.h>

void str_ncpy(char *s,int n, char *t)
{
	int i, c = strlen(s);
	for (i = 0; i < n; i++)
	{
		if (i == c)
		{
			*(t+i) = '\0';
			return;
		}
		else
		{
			*(t+i) = *(s+i);
		}
	}
	*(t+i) = '\0';
}

void str_ncat(char *s, int n, char *t)
{
	int i;
	int c = strlen(s);
	int d = strlen(t);
	for (i = c; i < c + n ; i++)
	{
		if (i == d + c)
		{
			*(s+i) = '\0';
			return;
		}
		else
		{
			*(s+i) = *(t+i-c);
		}
	}
	*(s+i) = '\0';
}

int str_ncmp(char *s, int n, char *t)
{
	int i;
	int c = strlen(s) , d = strlen(t);
	if (n>c)
	n =c;
	if (n>d)
	n=d;
	for(i = 0; i<n;i++)
	{	
		if (*(s+i) != *(t+i))
		{
			return -1;
		}
	}
	return 1;
}

int main()
{
	char s[50] = "hello ";
	char t[50] = "heo";
	int n = 3;
	//str_ncpy(s,n,t);
	//str_ncat(s,n,t);
	int x = str_ncmp(s,n,t);
	printf("%d\n",x);
}
