#include <stdio.h>

void printstar(int n)
{
	if (n <= 0)
	{
		printf("\n");
		return;
	}
	printstar(n-1);
	printf("*");
	printstar(n-1);

}

int main()
{
	int starnumber;
	scanf("%d",&starnumber);
	printstar(starnumber);
}

