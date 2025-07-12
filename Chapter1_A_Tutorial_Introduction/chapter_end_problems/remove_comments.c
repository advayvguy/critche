//there is a problem with this program
//it fails one edge case- if i have (" " ") somewhere in the middle the state stays as 1 and proceeds to print everything after this.
#include <stdio.h>

int main()
{
    int c;
    int i =0;
    char array[10000];
    while((c = getchar())!=EOF)
    {
        array[i] = c;
        i++;
    }
    array[i] = '\0';
    int max = i-1;
    /*check*/
    int pointer = 0;
    int state=0;
    int state_comment =0;

    while(pointer <= max)
    {
        //stuff to do when the pointer is inside the single and double quotes (exception)
        if(pointer <= max &&(array[pointer] == '\"' || array[pointer] == '\''))
        {
            state = 1;
            while(state==1)
            {
                printf("%c",array[pointer]);
                pointer++;
                if(pointer == max)
                {
                    state = 0;
                }

                /* boundary checks */
                if (array[pointer] == '\"' || array[pointer] == '\'')
                {
                    state = 0;
                }
            }
        }
        else
        {
            if(pointer <= max-1 && (array[pointer] == '/' && array[pointer+1] == '*'))
            {
                state_comment = 1;
                while(state_comment == 1)
                {
                    if (pointer <= max-1 && (array[pointer] == '*' && array[pointer+1] == '/'))
                    {
                        state_comment = 0;
                        pointer++;
                    }
                    pointer++;
                }
            }
            else
            {
                printf("%c",array[pointer]);
                pointer++;
            }
        }

    }
}
/* this is the end of the file */