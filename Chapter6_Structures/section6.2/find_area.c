#include <stdio.h>

struct point
{
    int x;
    int y;
};
struct rect
{
    struct point p1;
    struct point p2;
};

struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int findarea(struct rect rectangle)
{
    int diff_in_x, diff_in_y;
    if (rectangle.p1.x > rectangle.p2.x) 
    {
        diff_in_x = rectangle.p1.x - rectangle.p2.x;
    }
    else 
    {
        diff_in_x = rectangle.p2.x - rectangle.p1.x;
    }
    if (rectangle.p1.y > rectangle.p2.y)
    {
        diff_in_y = rectangle.p1.y - rectangle.p2.y;
    }
    else
    {
        diff_in_y = rectangle.p2.y - rectangle.p1.y;
    }
    return diff_in_x*diff_in_y;
}

int main()
{
    struct rect r1;
    r1.p1 = makepoint(4,5);
    r1.p2 = makepoint(10,10);
    int area = findarea(r1);
    printf("%d\n",area);
}