#include <stdio.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int getl(char s[])
{
	int c, i = 0;
	while ((c = getchar())!='\n')
	{
		if (c == EOF)
		{
			return -1; 
		}
		s[i++] = c;
	}
	s[i] = '\0';
	return 0;
}

double val[1000];
int valp = 0;

double operator(int f)
{
	switch (f)
	{
	case '+':
		return val[valp-1] + val[valp-2];
		printf("checksum\n");
		break;
	case '-':
		return val[valp-2] - val[valp-1];
		break;
	case '*':
		return val[valp-2] * val[valp-1];
		break;
	case '/':
		return val[valp-1] == 0 ? DBL_MIN : val[valp-2] / val[valp-1];	
		break;
	default:
		printf("unknown command %c\n",f);
		break;
	}
	return 0;	
}

int main()
{
	char s[1000], subarr[1000];
	int type,subp =0;
	double retval;
	while((type = getl(s)) != -1)
	{
		for(int sp =0; sp < strlen(s); sp++)
		{
			if(s[sp] == '.' && !isdigit(s[sp+1]))
			{
				printf("error: no number after \'.\'");
			}
			else if(sp > 0 && !isdigit(s[sp]) && isdigit(s[sp-1]) && s[sp] != '.')
			{
				subarr[subp] = '\0';
				val[valp++] = atof(subarr);
				subp = 0;
			}
			if (s[sp] == ' ' || s[sp] == '\t' )
			{
				;
			}
			else if (!isdigit(s[sp]) && s[sp] != '.')
			{
				retval = operator(s[sp]);
			 	if (retval == DBL_MIN)
				{
					break;
				}
				if (valp>1)
				{
					val[valp-2] = retval;
					valp--;
				}
				else
				{
					printf("error: missing operands \n");
				}
			}
			else if (isdigit(s[sp]) || (s[sp] == '.' && isdigit(s[sp+1])))
			{
				subarr[subp++] = s[sp]; 
			}
		}
		if (retval == DBL_MIN)
		{
			printf("error: cant divide a number by 0\n");
		}
		else if (subp>0)
		{
			subarr[subp] = '\0';
			printf("\t %s \n",subarr);
			subp = 0;
		}
		else if (valp > 1)
		{
			printf("error: missing operators \n");
			break;
		}
		else if (valp == 0)
		{
			printf("stack empty \n");
		}
		else
		{
			printf("\t %.8lf \n",val[0]);
		}
		valp = 0;
	}
}
