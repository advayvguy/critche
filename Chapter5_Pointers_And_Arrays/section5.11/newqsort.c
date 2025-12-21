#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int left, int right, int a[])
{
    if (left >= right) return;
    int pivot = a[left];
    int p1 = left + 1;
    int p2 = right;
    while (p1 <= p2)
    {
        if (a[p2] >= pivot) p2--;
        else if (a[p1] <= pivot) p1++;
        else swap(&a[p1], &a[p2]);
    }
    swap(&a[left], &a[p2]);
    sort(left, p2-1, a);
    sort(p2+1,right, a);
}

int main() 
{
    int a[1000];
    for (int i = 0; i < 1000; i++) scanf("%d",a+i);
    sort(0,999,a);
    for (int i = 0; i < 1000; i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
