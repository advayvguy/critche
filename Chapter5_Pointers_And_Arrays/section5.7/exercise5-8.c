//month,day -> yearday
//yearday -> month day

#include <stdio.h>

int daytab[2][13] = 
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int monthday_to_yearday(int month, int day, int year)
{
    int leap = ((year%4 == 0 && year%100 != 0) || year%400 == 0);
    if (year < 0)
    {
        printf("year cant be less than 0\n");
        return 0;
    }
    if (month > 12 || month < 1)
    {
        printf("month number should be between 1 and 12\n");
        return 0;
    }
    if (daytab[leap][month] < day)
    {
        printf("month numer %d only has %d days\n", month, daytab[leap][month]);
        return 0;
    }
    int monthsum = 0;
    for(int i = 1; i < month; i++)
    {
        monthsum += daytab[leap][i];
    }
    return day + monthsum;
}

int yearday_to_monthday(int yearday, int year, int *month, int *day)
{
    int leap = ((year%4 == 0 && year%100 != 0) || year%400 == 0); 
    if (yearday < 0 || yearday > 365 + leap)
    {
        printf("yearday cant be less than %d or greater than %d\n",0, 365 + leap);
        return 0;
    }
    if (year < 0)
    {
        printf("year cant be less than 0");
        return 0;
    }
    int i;
    for(i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *day = yearday;
    *month = i;
    return 1;
}

int main()
{
    int month = 2,day = 26;
    int year = 2007;
    int yearday = monthday_to_yearday(month,day,year);
    if (yearday != 0)
    {
        printf("%d\n",yearday);
    }
    int dayofyear = 366;
    int check = yearday_to_monthday(dayofyear, year, &month, &day);
    if (check != 0)
    {
        printf("%d %d\n",day,month);
    }
}