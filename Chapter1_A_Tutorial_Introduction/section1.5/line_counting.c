#include <stdio.h>

int main()

{
    int nl,c; // if we just define something i guess we assume its value to be 0
    printf("%d \n",'\n');
    for (int i=0;  (c = getchar()) != EOF; i++) // != has more priority than =
    {
        if (c == '\n')
            nl++;
    }
    printf("%d \n",nl);
}

//note that \n stores integer value 