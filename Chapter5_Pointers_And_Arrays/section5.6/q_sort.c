#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void q_sort(int *arr, int count)
{
	
}

int main()
{
	int arr[] = {9,3,7,1,5};
	q_sort(arr,0,4);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n",arr[i]);
	}
}

