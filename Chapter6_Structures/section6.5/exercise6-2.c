#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int first = 6;
    if (argc > 1 && argv[1][0] == '-') first = atoi(argv[1] + 1);
    
}