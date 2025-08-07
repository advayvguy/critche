#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
//made a macro to swap two entities of a given type.
#define swap(t,x,y) {t temp = x; x = y; y = temp;}

int main()
{
	int n = 40;
	int m = 30;
	swap(int,n,m);
	printf("%d\n",n);
}
