#include <stdio.h>

int main()
{
    struct point
    {
        int x;
        int y;
    };

    struct point pt;
    pt.x = 5;
    pt.y = 3;
    
    struct rect
    {
        struct point p1;
        struct point p2;
    };
    struct rect r1;
    r1.p1.x = 4;
    r1.p1.y = 3;
    r1.p2.x = 5;
    r1.p2.y = 4;
}