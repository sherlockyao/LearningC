#include <stdio.h>

static char *daytab[] = {
    "\0\x1f\x1c\x1f\x1e\x1f\x1e\x1f\x1f\x1e\x1f\x1e\x1f",
    "\0\x1f\x1d\x1f\x1e\x1f\x1e\x1f\x1f\x1e\x1f\x1e\x1f"
};

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i < month; i++) {
        day += *(daytab[leap] + i);
    }
    return day;
}

main()
{
    printf("%d\n", day_of_year(2017, 3, 2));
}
