#include <stdio.h>
//nice 
int main()
{
    char a[1000];
    int i=0;
    int c;
    while((c = getchar())!=EOF)
    {
        a[i] = c;
        i++;
    }
    a[i] = '\0';
    for(int j = 0; j<i; j++)
    {
        printf("%c",(a[j] >= 'A' && a[j] <= 'Z' ) ? a[j] + ('a' - 'A') : a[j]);
    }
}