#include <stdio.h> //include the standard input output library 

int main() //define a fuction 'main' which recieves no argument values 
{
    printf("hello, world\n"); //this function belongs to the stdio.h library 
    
    //you can also write the same code like this-

    printf("hello, ");
    printf("world");
    printf("\n");    
    return 0;

}

//now what if you want a double quote itself?

// well then we can write this - printf("\"hello world\"");