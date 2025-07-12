#include <stdio.h>

int main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    {
        printf("%3d%7.2f\n",fahr,(5.0/9.0)*(fahr+32.0)); // can also write ("%3d %6.2f\n")
    }
    
}

//why the for when while exists?
//its a matter of convinience, in a for loop you can state all the constraints in one place.