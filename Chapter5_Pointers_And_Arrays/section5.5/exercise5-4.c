#include <stdio.h>
#include <string.h>

int str_end(char *s, char *t)
{
	if (strlen(t) > strlen(s))
	{
		return 0;
	}
	int temp = strlen(t)-1;
	t = t + temp;
	s = s + strlen(s) -1;
	for (int j = temp; j >= 0; j--)
	{
		if (*(s--) != *(t--))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
    	char s[] = "hello world";
    	char t1[] = "world";
    	char t2[] = "wold";
    	char t3[] = "hello world!";
    	char t4[] = "hello world";

    	printf("%d\n", str_end(s, t1)); // 1
    	printf("%d\n", str_end(s, t2)); // 0
    	printf("%d\n", str_end(s, t3)); // 0
    	printf("%d\n", str_end(s, t4)); // 1
}
