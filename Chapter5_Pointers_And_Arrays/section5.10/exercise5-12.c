//lol i didnt read the question properly and did something else altogther.
//nevermind that though, the question seems easy enough.
//arguably even easier than this i reckon

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//extend entab to accept shorthand notations
//entab -m +n -> tab stops every n columns starting from m

//if numcols is not given- numcols = length-m -> we would be entabbing all the way till the end
//if initcol is not given- initcol = 0

int fetch(char *buff)
{
	int i,c;
	for (i=0; (c = getchar()) != EOF; i++)
	{
		buff[i] = c;
	}
	buff[i] = '\0';
	return i;
}

void printfunc(char *s,int m,int n,int len)
{
	int i;
	for (i = 0; i<m; i++)
	{
		printf("%c",s[i]);
	}
	for (i = m; i<n+m && i < len; i++)
	{
		//real problem
		//we need to run entab only until n columns starting from m
		if (s[i] != ' ')
		{
			printf("%c",s[i]);
		}
		else
		{
			int chunkend = ((i/8 + 1)*8 < len) ? (i/8+1)*8 : len;
			int check = 0;
			for (int j = i; j < chunkend; j++)
			{
				if (s[j] != ' ')
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				printf("%c",s[i]);
			}
			else
			{
				printf("\t");
				i = chunkend-1;
			}
		}
	}
	for (i = n+m; i < len; i++)
	{
		printf("%c",s[i]);
	}
}

int main(int argc, char **argv)
{
	//fetches m and n here
	int initcol = 0, numcols = 0;
	if (argc >=2 && *argv[1] == '-')
	{
		int len1 = strlen(argv[1]);
		for (int i = 1; i < len1; i++)
		{
			initcol = (*(argv[1] + i)-'0') + initcol*10;
		}
	}
	if (argc == 3 && *argv[2] == '+')
	{
		int len2 = strlen(argv[2]);
		for (int i = 1; i < len2; i++)
		{
			numcols = (*(argv[2] + i)-'0') + numcols*10;
		}
	}
	//printf("%d, %d\n",initcol, numcols);
	
	char buff[10000];
	int len = fetch(buff);
	if (argc <= 2)
	{
		numcols = len-initcol;
	}
	printfunc(buff,initcol,numcols,len);
}












