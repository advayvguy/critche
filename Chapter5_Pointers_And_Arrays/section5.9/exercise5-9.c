#include <stdio.h>

char *month_name(int n)
{
    //static because we want main to remember this array for the entirity of the program.
    //all of this is put in .rodata (read only memory)
    //char *s is actually const char *s, so you cant change it.
    //address = base + (row * COLS) + col thats why coloumn number must be specified at complile time because the compiler needs to know how many coloums to jump for the next row.
    char *months[]= 
    {
        "Illegal month",
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep",
        "Oct",
        "Nov",
        "Dec"
    };
    return (n < 1 || n > 12) ? months[0] : months[n];
}

int daysofmonth(int monthnum, int leap)
{
    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (monthnum == 2 && leap)
    {
        return 29;
    }
    return days[monthnum];
}

//print the month and the day from yearday,


int monthday_to_yearday(int year, int month, int day)
{
    int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (year < 0 || month > 12 || month < 0 || day > daysofmonth(month,leap))
    {
        printf("input error\n");
        return 0;
    }
    int yearday = day;
    for (int i = 1; i < month; i++)
    {
        yearday += daysofmonth(i,leap);
    }
    return yearday;
}

int yearday_to_monthday(int yearday, int year, int *month, int *day)
{
    int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (yearday < 0 || yearday > leap + 365 || year < 0)
    {
        printf("input error\n");
        return 0;
    }
    int i;
    for(i = 1; yearday > daysofmonth(i,leap); i++)
    {
        yearday -= daysofmonth(i,leap);
    }
    *day = yearday;
    *month = i;
    return 1;
}

int main()
{
    int month = 12, day = 31;
    int year = 1900;
    int yearday = monthday_to_yearday(year, month, day);
    if (yearday == 0)
    {
        return 0;
    }
    printf("%d\n",yearday);
    int check = yearday_to_monthday(366, year, &month, &day);
    if (check != 0)
    printf("%s, %d\n",month_name(month), day);
}