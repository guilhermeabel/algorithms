#include <stdio.h>
#include <stdlib.h>

int dateTest(int day, int month, int year)
{
    if (year < 1900 || year > 2019)
    {
        char invalidYear[] = "Please insert a valid year. \n";
    }
    if (month < 1 || month > 12)
    {
        char invalidMonth[] = "Please insert a valid month. \n";
    }

    if (day < 1 || day > 31)
    {
        char invalidDay[] = "Please insert a valid day. \n";
    }
}

int main()
{
}