#include <stdio.h>
#include <stdlib.h>

//finally works :) 

int main (int argc, char **argv)
{
	int m = 0, n = 8;
	if (argc > 1 && argv[1][0] == '-') m = atoi(argv[1] + 1);
	if (argc > 2 && argv[2][0] == '+') n = atoi(argv[2] + 1);

	char s[10000];
	int len, c;
	for (len = 0; (c = getchar()) != EOF; len++)
	{
		s[len] = c;
 	}
	s[len] = '\0';
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		if (pos < m || pos >= m+n)
		{
			if (s[i] == '\t') pos += 8 - (pos%8);
			else if (s[i] == '\n') pos = 0;
			else pos++;
			putchar(s[i]);
		}
		else
		{
			if (s[i] == '\t')
			{
				pos += 8 - (pos%8);
				putchar('\t');
			}
			else if (s[i] == '\n')
			{
				pos = 0;
				putchar('\n');
			}
			else if (s[i] == ' ')
			{
				int nb;
				for(nb = 0; s[i] == ' ' && s[i] != '\n' && s[i] != '\0'; nb++)
				{
					if ((pos + 1)%8 == 0)
					{
						nb = 0;
						putchar('\t');
					}
					pos++;
					i++;
				}
				for (int j = 1; j < nb; j++) putchar(' ');
				i--;
			}
			else
			{
				putchar(s[i]);
				pos++;
			}
		}
	}
}