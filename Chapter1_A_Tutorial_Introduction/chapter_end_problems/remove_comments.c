//this is nice
#include <stdio.h>

int main()
{
	//reads the input file
	int c, i;
	char to[1000], from[1000];
	int s1 = -1, s2 = -1;

	for(i=0; (c=getchar()) != EOF; i++)
	{
		to[i] = c;
	}
	to[i] = '\0';
	//the code
	int p1=0,p2=0;
	while(p1<i)
	{
		if(to[p1] == '\\')
		{
			from[p2++] = to[p1++];
			from[p2++] = to[p1++];
		}
		else if(to[p1] == '\'')
		{
			from[p2++] = to[p1++];
			s1*=-1;
		}
		else if(to[p1] == '\"')
		{
			from[p2++] = to[p1++];
			s2*=-1;
		}

		else if(s1 == -1 && s2 == -1)
		{
			if(p1<i && to[p1] == '/' && to[p1+1] == '*')
			{
				p1+=2;
				while(p1<i && to[p1] != '*' && to[p1+1] != '/')
				{
					p1++;
				}
				p1+=2;
			}
			else if(p1<i && to[p1] == '/' && to[p1+1] == '/')
			{
				p1+=2;
				while(p1<i && to[p1] != '\n')
				{
					p1++;
				}
			}
			else
			{
				from[p2++] = to[p1++];
			}
		}
		else
		{
			from[p2++] = to[p1++];
		}		
	}
	from[p2] = '\0';
	printf("%s\n",from);
}


















