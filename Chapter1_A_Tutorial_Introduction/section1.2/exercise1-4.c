#include <stdio.h>

int main()
{
    int step = 10;
    int upper = 100;
    int lower = 0;

    float celcius = lower;

    while (celcius<= upper)
    {
        float fahrenheit = (9.0/5.0)*(celcius) +32.0;
        printf ("%3.0f %6.1f\n",celcius,fahrenheit);
        celcius = celcius + step;
    }
}