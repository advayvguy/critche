//also a revision of that concept.
//rpc with no space handling.
//the code is pretty inelegant.
#include <stdio.h>
#include <string.h>
#define MAXBUF 10000

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

int operate(int a, int b, char c)
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
            return b/a;
        }
        default:
        {
            printf("error operator");
            return 0;
            break;
        }
    }
}

int main(int argc , char **argv)
{
    int bufp = 0;
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
        }
        else
        {
            int ans = operate(*(buf + (bufp - 2)), *(buf + (bufp - 1)), **(argv + i));
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
        printf("error in expression\n");
    }
}
