#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i = 0; i < argc + 20 ; i++) //why am i getting extra stuff here.
    {
        printf("%s%s", *(argv+i), " ");
    }
    printf("\n");
    return 0;
}