/**
 * Solution by Luis Galotti
 * This solution need the file problem18CompanionFile (where is written the tree)
 * You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>
#include <string.h>

using namespace std;
const int maxNum = 15;
const int MAX = 100;

struct day {
    int weekDay;
    int dayOfMonth;
    int month;
    int year;
};

const day startingDay = {0, 0, 0, 1900};

const int maxDaysInMoth[12] =  {31,
                            28,
                            31,
                            30,
                            31,
                            30,
                            31,
                            31,
                            30,
                            31,
                            30,
                            31};

bool isLeapYear( int year ){
	bool leap = false;
	if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0) leap = true;
        } else leap = true;
	}
	return leap;
}

day addYear(day baseDay, int numYear){
   day newDay = baseDay;
       for (int i = 0; i < numYear; i++ ){

   if ((isLeapYear(newDay.year) and newDay.month < 2) or (isLeapYear(newDay.year + 1) and newDay.month > 1)){
    newDay = {(newDay.weekDay + 2) % 7,
                newDay.dayOfMonth,
                newDay.month,
                newDay.year +1};
   }else {
    newDay = {(newDay.weekDay + 2) % 7,
                newDay.dayOfMonth,
                newDay.month,
                newDay.year +1};}}
    return newDay;
}

day addMonth(day baseDay, int numMonths){
    day newDay = baseDay;
    for (int i = 0; i < numMonths; i++ ){
        if (newDay.month == 11){
            newDay = {(newDay.weekDay + 3)%7,
                    newDay.dayOfMonth,
                    0,
                    newDay.year + 1};
        } else if (newDay.month == 1){
            if (isLeapYear(newDay.year)) {
                newDay = {(newDay.weekDay + 1)%7,
                newDay.dayOfMonth,
                newDay.month + 1,
                newDay.year};
            }else {
                newDay = {newDay.weekDay,
                newDay.dayOfMonth,
                newDay.month + 1,
                newDay.year};
            }}else if(newDay.month == 0 or newDay.month == 4 or newDay.month == 6 or newDay.month == 7 or newDay.month == 9){
               newDay = {(newDay.weekDay + 3)%7,
               newDay.dayOfMonth,
               newDay.month + 1,
               newDay.year};
        } else{
            newDay = {(newDay.weekDay + 2)%7,
            newDay.dayOfMonth,
            newDay.month + 1,
            newDay.year};
        }
    }

    return newDay;
}

day addWeek(day baseDay, int numWeek){
    day newDay = baseDay;
    for (int i = 0; i < numWeek; i++ ){
    if (newDay.month == 1 and isLeapYear(newDay.year)){
           if (newDay.dayOfMonth + 7 >= maxDaysInMoth[1]){
                newDay = {newDay.weekDay,
                (newDay.dayOfMonth + 7) % (maxDaysInMoth[1] + 1),
                newDay.month + 1,
                newDay.year};
           }}else{
                if (newDay.month == 11 and newDay.dayOfMonth + 7 >= 30 ){
                    newDay = {newDay.weekDay,
                    ((newDay.dayOfMonth + 7) % 30),
                    0,
                    newDay.year +1 };
                }else if (newDay.dayOfMonth + 7 >= maxDaysInMoth[newDay.month] - 1){
                    newDay = {newDay.weekDay,
                    (newDay.dayOfMonth + 7) % (maxDaysInMoth[newDay.month] - 1),
                    newDay.month + 1,
                    newDay.year}; }
                    else {
                    newDay = {newDay.weekDay,
                    (newDay.dayOfMonth + 7) % (maxDaysInMoth[newDay.month] - 1),
                    newDay.month,
                    newDay.year};}} }

    return newDay;
}

day addDay(day baseDay, int numDays){
    day newDay = baseDay;
    for (int i = 0; i < numDays; i++ ){
    if (newDay.month == 1 and isLeapYear(newDay.year)){
           if (newDay.dayOfMonth + 1 >= maxDaysInMoth[1]){
                newDay = {(newDay.weekDay +1) % 7,
                (newDay.dayOfMonth + 1) % (maxDaysInMoth[1] + 1),
                newDay.month + 1,
                newDay.year};
           }}else{
                if (newDay.month == 11 and newDay.dayOfMonth + 1 >= 30 ){
                    newDay = {(newDay.weekDay +1) % 7,
                    ((newDay.dayOfMonth + 1) % 30),
                    0,
                    newDay.year +1 };
                }else if (newDay.dayOfMonth + 1 >= maxDaysInMoth[newDay.month] - 1){
                    newDay = {(newDay.weekDay +1) % 7 ,
                    (newDay.dayOfMonth + 1) % (maxDaysInMoth[newDay.month] - 1),
                    newDay.month + 1,
                    newDay.year}; }
                    else {
                    newDay = {(newDay.weekDay +1) % 7,
                    (newDay.dayOfMonth + 1) % (maxDaysInMoth[newDay.month] - 1),
                    newDay.month,
                    newDay.year};}} }

    return newDay;
}

int main()
{
    day actualDay = startingDay;

    bool continuar = false;

    actualDay = addYear(actualDay, 1);
    int contMonday = 0;
    for (int i = 0; i < 100; i++){

        day dayAux = actualDay;
        bool isMonday = dayAux.weekDay == 0;
        while (!isMonday){
            dayAux = addDay(dayAux, 1);
            isMonday = dayAux.weekDay == 0;
            }
        contMonday = contMonday + 4;
        dayAux = addWeek(dayAux, 4);
        if (dayAux.month == 0) contMonday++;

        actualDay = addYear(actualDay,1);
    }
    printf("Solution = %i",contMonday);
    return 0;
}
