#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//day_of_year converts month day to the year day ordinal
//month_day converts the year day to the month day

//2d array:-
//char can be used to store small non negative integers (256 bits then it overflows)

const char daytab[2][13] = 
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year%4 == 0 && year%100 != 0) || year%400;
	for (i = 1; i < month; i++)
	{
		day += daytab[leap][i];
	}
	return day;
}

//this should return some value from the daytab
void month_day (int yearday, int year, int *day, int *mon)
{
	int i;
	int leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
	{
		yearday -= daytab[leap][i];
	}
	*day = yearday;
	*mon = i;
}

//possible errors:- day > 365/366 and year is negative.
int main()
{
	int yearday = 61, year = 2008;
	int day, month;
	month_day(yearday, year, &day, &month);
	printf("%d %d",day, month);
}

