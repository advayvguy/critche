#include <stdio.h>

float convert(int fahr)
{
    float celcius = 5.0*(fahr-32)/9;
    return celcius;
}

int main()
{
    int fahr;
    for(fahr=0; fahr <= 300; fahr = fahr +20)
    {
        printf("%3d %8.2f\n",fahr,convert(fahr));
    }
}