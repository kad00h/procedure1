#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year)
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    return 31;
}

int getFirstDayOfMonth(int month, int year)
{
    struct tm time_in = {0, 0, 0, 1, month - 1, year - 1900};
    time_t time_temp = mktime(&time_in);
    struct tm *time_out = localtime(&time_temp);
    return time_out->tm_wday;
}

void printMonthName(int month)
{
    const char *monthNames[] = {"Січень", "Лютий", "Березень", "Квітень", "Травень", "Червень", "Липень", "Серпень", "Вересень", "Жовтень", "Листопад", "Грудень"};
    printf("Місяць: %s\n", monthNames[month - 1]);
}

void printCalendar(int month, int year)
{
    int daysInMonth = getDaysInMonth(month, year);
    int firstDay = getFirstDayOfMonth(month, year);

    printMonthName(month);
    printf("Рік: %d\n\n", year);

    printf("Пн  Вт  Ср  Чт  Пт  Сб  Нд\n");

    int currentDay = 1;
    int currentWeekDay = (firstDay == 0) ? 6 : firstDay - 1; //
    for (int i = 0; i < currentWeekDay; i++)
    {
        printf("    ");
    }

    for (int i = currentWeekDay; i < 7; i++)
    {
        printf("%2d  ", currentDay++);
    }
    printf("\n");

    while (currentDay <= daysInMonth)
    {
        for (int i = 0; i < 7 && currentDay <= daysInMonth; i++)
        {
            printf("%2d  ", currentDay++);
        }
        printf("\n");
    }
}

int main()
{
    int month, year;

    printf("Введіть місяць (1-12): ");
    scanf("%d", &month);
    printf("Введіть рік: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 0)
    {
        printf("Неправильний місяць або рік. Спробуйте ще раз.\n");
        return 1;
    }

    printCalendar(month, year);

    return 0;
}
