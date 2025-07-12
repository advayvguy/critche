//to convert string to a double
#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
    double val,power;
    int i,sign;
    for (i=0;isspace(s[i]);i++) //skip the white spaces
    {
        ;
    }
    sign = (s[i] == '-') ? -1:1;
    if (sign == '+' || sign == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]);i++)
    {
        val = 10.0*val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0*val +(s[i] - '0');
        power *= 10.0;
    }
    return sign*val/power;
}

int main()
{
    char s[] = "  235.578";
    printf("%8.4lf\n",atof(s));
}










