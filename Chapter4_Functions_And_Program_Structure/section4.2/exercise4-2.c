#include <stdio.h>
#include <ctype.h>
#include <string.h>

double atof(char s[])
{
double val,power;
int i, sign, expsign,exp=0;

for (i=0; isspace(s[i]); i++)
{
    ;
}
sign = (s[i] == '-') ? -1:1;
if (s[i] == '-' || s[i] == '+')
{
    i++;
}
for(val = 0.0; isdigit(s[i]); i++)
{
    val = 10*val + (s[i] -'0');
}
if (s[i] == '.')
{
    i++;
}
for (power = 1.0; isdigit(s[i]); i++)
{
    val = 10*val + (s[i] - '0');
    power *= 10.0;
}
double value = sign*val/power;
if (s[i] == 'e' || s[i] == 'E')
{
    i++;
}
expsign= (s[i++] == '+') ? 1:-1;
for (exp=0; isdigit(s[i]); i++)
{
    exp = 10*exp + (s[i] - '0');
}
for(int k = exp; k>0;k--)
{
    if (expsign == 1)
    {
        value *= 10;
    }
    else
    {
        value /=10;
    }
}
return value;
}

int main()
{
    char s[] = "123.45e-6";
    printf("%10.8lf\n",atof(s));
}