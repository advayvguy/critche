#include <stdio.h>

int binsrch(int x, int v[], int n)
{
    int low = 0, high = n-1, mid = (n-1)/2;
    while (low<=high && v[mid] != x) //what I was assuming was this statement v[mid] != x also counts as a 'test in loop'
    {
        mid = (high + low)/2;
        if (v[mid] > x)
        {
            high = mid-1;
        }
        else
        {
            low = mid +1;
        }
    }
    if (v[mid] == x)
    {
        return mid;
    }
    else
    {
        return -1;
    }

}

int main()
{
    int x = 5;
    int array[5];
    array[0] = 1, array[1] = 2, array[2] = 3, array[3]=4, array[4]=6;
    int n = 5;
    printf("%d\n",binsrch(x,array,n));
}