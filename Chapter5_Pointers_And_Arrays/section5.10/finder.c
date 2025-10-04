// >./search2 hello -> prints lines with hello in them
// >./search2 hello -x -> prints all lines eXcept those that contain helll
// > -n -> line numbering
// >./search2 -x -n pattern -> does both, so does -xn.

#include <stdio.h>
#include <string.h>
#define MAXLINE 10000

//basic getline function
int get_line(char *line, int max)
{
    int c,i;
    for  (i = 0; (c = getchar()) != '\n'; i++)
    {
        if (c == EOF)
        {
            printf("end of program\n");
            return -1;
        }
        if (i == max)
        {
            printf("reached size limit\n");
            return 1;
        }
        *(line + i) = c;
    }
    *(line + i) = '\0';
    return 1;
}

int main(int argc, char **argv)
{
    char line[MAXLINE];
    long linenum = 0;
    int c,except = 0, number = 0, found = 0;
    while(--argc > 0 && *(*(++argv)) == '-') //'-' should be the first element of the second string
    //--argc>0 runs the loop only over commands entered by you **(++argv) checks if the second or the third string has '-' as its first character.
    {
        while (c = *(++(*argv))) //null terminator's ascii value is 0
        {
            switch(c)
            {
                case 'x':
                {
                    except =1;
                    break;
                }
                case 'n':
                {
                    number = 1;
                    break;
                }
                default:
                {
                    printf("illegal operation\n");
                    argc = 0;
                    found = -1;
                    break;
                }
            }
        }
    }
    if (argc != 1)
    {
        printf("incorrect usage\n");
    }
    else
    {
        while (get_line(line, MAXLINE) > 0)
        {
            linenum++;
            if((strstr(line, *argv) != 0) != except) //the former returns 1 if it did find a match.
            {
                if(number)
                printf("(%ld) ",linenum);
                printf("%s\n",line);
                found++;
            }
        }
    }
    return found;
}