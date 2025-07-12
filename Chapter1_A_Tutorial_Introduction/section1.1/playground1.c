#include <stdio.h>

int main()
{
    printf("\" hello \"\n");  // \"->in case you want to insert a double quote.
    printf("\\ hello \\\n"); //->in case you want to insert a hyphen 
    printf("\t hello \t world"); // \t->in case you want to insert a tab
    return 0;
}