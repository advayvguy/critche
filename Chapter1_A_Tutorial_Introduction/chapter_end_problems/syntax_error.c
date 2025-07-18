#include <stdio.h>

int main()
{
    /*fetching the data */
    int c;
    char array[10000];
    int i = 0;
    while((c = getchar())!= EOF)
    {
        array[i] = c;
        i++;
    }
    array[i] = '\0';
    int max = i-1;
    int state1 = 0;
    int state2 = 0;
    int state3 = 0;

    /*the actual code*/
    for(int pointer = 0; pointer<=max; pointer++)
    {
        if (pointer<=max && array[pointer] == '/' && array[pointer+1] == '*')
        {
            pointer = pointer+2;
            while(pointer<= max && array[pointer] != '*' && array[pointer + 1]!= '/')
            {
                pointer++;
            }
            pointer++;
        }
        else if(pointer<=max && array[pointer] == '\'')
        {
            int temp = pointer;            
            pointer++;            
            while(pointer<=max && array[pointer]!='\'')
            {
                if (array[pointer] == '/' && array[pointer+1] == '*')
                {
                    pointer = pointer + 2;
                    while (array[pointer] != '*' && array[pointer+1] != '/')
                    {
                        pointer++;
                    }
                }                
                else if(array[pointer] == '\\')
                {
                    pointer++;
                }
                else if(array[pointer] == '\n')
                {
                    printf("no closure to the (\')\n");
                    pointer = temp;
                    break;
                }
                pointer++;
            }
        }        
        else if(pointer<=max && array[pointer] == '\"')
        {
            int temp = pointer;            
            pointer++;            
            while(pointer<=max && array[pointer]!='\"')
            {
                if (array[pointer] == '/' && array[pointer+1] == '*')
                {
                    pointer = pointer + 2;
                    while (array[pointer] != '*' && array[pointer+1] != '/')
                    {
                        pointer++;
                    }
                }
                else if(array[pointer] == '\\')
                {
                    pointer++;
                }
                else if(array[pointer] == '\n')
                {
                    printf("no closure to the (\")\n");
                    pointer = temp;
                    break;
                }
                pointer++;
            }
        }
        else if(pointer <= max && array[pointer] == '[')
        {
            state1++;
        }
        else if(pointer <= max && array[pointer] == '{')
        {
            state2++;
        }
        else if(pointer <= max && array[pointer] == '(')
        {
            state3++;
        }
        else if(pointer<=max && array[pointer] == ']')
        {
            if (state1 == 0)
            {
                printf("unexpected \'%c\'\n",array[pointer]);
            }
            else
            {
                state1--;
            }
        }
        else if(pointer<=max && array[pointer] == '}')
        {
            if (state2 == 0)
            {
                printf("unexpected \'%c\'\n",array[pointer]);
            }
            else
            {
                state2--;
            }
        }
        else if(pointer<=max && array[pointer] == ')')
        {
            if (state3 == 0)
            {
                printf("unexpected \'%c\'\n",array[pointer]);
            }
            else
            {
                state3--;
            }
        }
        else if(pointer == max && (state1 != 0 || state2 != 0 || state3 != 0))
        {
            if(state1 != 0)
            {
                printf("there is no closure to \'[\'\n");
            }
            else if(state2 != 0)
            {
                printf("there is no closure to \'{\'\n");
            }
            else if(state3 != 0)
            {
                printf("there is no closure to \'(\'\n");
            }
        }
    }
}
