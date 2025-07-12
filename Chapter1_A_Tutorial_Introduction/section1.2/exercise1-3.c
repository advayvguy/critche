#include <stdio.h>

int main()
{
    int step = 20;
    int lower = 0;
    int upper = 300;

    float fahrenheit = lower;

    printf ("FAHRENHEIT\t|\tCELCIUS\n");
    printf("-----------------------\n");
    while (fahrenheit<=upper)
    {
        float celcius = (5.0/9.0)*(fahrenheit-32.0); 
        printf("%3.f\t\t|\t%6.1f\n",fahrenheit,celcius);
        printf("-----------------------\n");
        fahrenheit = fahrenheit + step;
    }
}
