#include <stdio.h>

int main()
{
    int step = 20;
    int lower = 0;
    int upper = 300;

    float fahrenheit = lower;

    while (fahrenheit<=upper)
    {
        float celcius = (5.0/9.0)*(fahrenheit-32.0); 
        printf("%3.0f\t%6.1f\n",fahrenheit,celcius);
        fahrenheit = fahrenheit + step;
    }
}

//if an operation has one floating point and another intger like F-32 then the 32 will be converted to its float value
//5.0/9.0 is seen as a float value whereas 5/9 is seen as an integer value and truncuated
//%6.1f -> at least 6 charecters wide and with one extra decimal place (.1f)
//say we want two decimal places- we use - %.2f