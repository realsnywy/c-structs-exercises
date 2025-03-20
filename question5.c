//! Question 5: Date Comparison with Pointers
// Create a struct called Date, containing:
//* Day (integer)
//* Month (integer)
//* Year (integer)
// Create a function that receives pointers to two Date structs and returns the latest date.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day, month, year;
} Date;

Date *createDate()
{
    Date *d = (Date *)malloc(sizeof(Date));
    return d;
}

Date *latestDate(Date *d1, Date *d2)
{
    if (d1->year > d2->year)
        return d1;
    else if (d1->year < d2->year)
        return d2;
    else
    {
        if (d1->month > d2->month)
            return d1;
        else if (d1->month < d2->month)
            return d2;
        else
        {
            if (d1->day > d2->day)
                return d1;
            else
                return d2;
        }
    }
}

// Instead of creating functions to register and display the date, I'm going to ask the user to input the date directly in the main function.
int main()
{
    Date *date1 = createDate();
    Date *date2 = createDate();

    printf("Enter the first date (dd mm yyyy): ");
    scanf("%d %d %d", &date1->day, &date1->month, &date1->year);
    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2->day, &date2->month, &date2->year);

    Date *latest = latestDate(date1, date2);

    printf("The latest date is: %d/%d/%d\n", latest->day, latest->month, latest->year);

    free(date1);
    free(date2);
    free(latest);

    return 0;
}