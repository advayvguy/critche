#include <stdio.h>

int main()
{
    int x = 1084227584;
    float a = (float)x;
    printf("%f\n",a);

    float *f = (float*)(&x);
    printf("%f\n",*f);
}