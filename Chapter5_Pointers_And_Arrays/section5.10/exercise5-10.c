//also a revision of that concept.
//rpc with no space handling.
//must be one of the worst pieces of code ever written.
#include <stdio.h>
#include <string.h>
#define MAXBUF 100000
int check_and_add(char *str, int *bufc)
{
    int num = 0,i=0;
    int sign = 1;
    int len = strlen(str);
    if (*str == '-' && len != 1)
    {
        sign = -1;
        i++;
    }
    while(i != len)
    {
        if(*(str+i) >= '0' && *(str+i) <= '9')
        {
            int number = *(str + i) - '0';
            num = 10*num + number;
        }
        else
        {
            return -1;
        }
        i++;
    }
    num *= (sign == -1) ?  -1:1;
    *bufc = num; 
    return 1;
}

int operate(int a, int b, char c, int *check)
{
    switch(c)
    {
        case '+':
        {
            return b+a;
        }
        case '-':
        {
            return b-a;
        }
        case '*':
        {
            return b*a;
        }
        case '/':
        {
            if (a == 0)
            {
                *check = 0;
                return 0;
            }
            return b/a;
        }
        default:
        {
            printf("error operator\n");
            return 0;
            break;
        }
    }
}

int main(int argc , char **argv)
{
    int bufp = 0;
    int divbyzero = 1;
    int buf[MAXBUF];
    for(int i = 1; i < argc; i++)
    {
        if (check_and_add(*(argv + i), buf+bufp) == 1)
        {
            bufp++;
        }
        else if (bufp < 2)
        {
            printf("not enough operands\n");
            return 0;
        }
        else
        {
            int ans = operate(*(buf + (bufp - 2)), *(buf + (bufp - 1)), **(argv + i), &divbyzero);
            if (!divbyzero)
            {
                printf("cant divide by 0\n");
                return 0;
            }
            *(buf + (bufp - 2)) = ans;
            bufp--;
        }
    }
    if (bufp == 1)
    {
        printf("%d\n",*buf);
    }
    else
    {
        printf("not enough operators\n");
    }
    return 0;
}