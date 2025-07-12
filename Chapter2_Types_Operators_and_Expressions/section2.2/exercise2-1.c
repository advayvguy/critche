#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("range of char: (%d,%d) \n",CHAR_MIN,CHAR_MAX);
    printf("range of short: (%d,%d) \n",SHRT_MIN,SHRT_MAX);
    printf("range of int: (%d,%d) \n",INT_MIN,INT_MAX);
    printf("range of long: (%ld,%ld) \n",LONG_MIN,LONG_MAX);
    printf("range of float: (%0.60f,%f) \n",FLT_MIN,FLT_MAX);
}
