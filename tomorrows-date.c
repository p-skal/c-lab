/* 
    Tomorrow's Date - A C Program

    A program that reads a date in dd/mm/yyyy format and
    prints (in the same format) the date that it will be tomorrow.
	
    ✅ Finished

	Peter S. - (https://twitter.com/ps300300)
	 * 07/18
*/
	
#include <stdio.h>
#include <stdlib.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define MIN_DAYS_IN_MONTH 1
#define MIN_MONTHS_IN_YEAR 1

#define LNG_MONTH 31
#define FEB_MONTH 28
#define REG_MONTH 30

#define MONTHS_IN_YEAR 12

//testing a function that adds new line by itself
void newline ()  {
    printf("\n");
}

int
main(int argc, char *argv[]) {
	int dd, mm, yyyy, mm_length;
    //i variable setup for loop incrementations
    int i;

    //prompt, then scan in current date
    printf("What is the current date? (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    //error checking for entered date (correct month-day setup + format)
    if ((mm > MONTHS_IN_YEAR) || (mm < MIN_MONTHS_IN_YEAR) || (dd < MIN_DAYS_IN_MONTH)|| (dd > LNG_MONTH)) {
        printf("Please ensure the date entered is correct (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &dd, &mm, &yyyy);
    }
    if ((mm > MONTHS_IN_YEAR) || (mm < MIN_MONTHS_IN_YEAR) || (dd < MIN_DAYS_IN_MONTH)|| (dd > LNG_MONTH)) {
        printf("\nThe entered date was incorrect 👎\nPlease reboot & try again using the correct format (dd/mm/yyyy).\n\n");
        return 0;
    }

    //provides month length for specified month - taking leap years into account
    for (i=1; i<=12; i++) {
        switch (mm) {
            case FEB:
                if ((yyyy & 3) == 0 && ((yyyy % 25) != 0 || (yyyy & 15) == 0)) {
                    mm_length = 28;
                } else {
                    mm_length = 29;
                }
                break;
            case APR:
            case JUN:
            case SEP:
            case NOV:
                mm_length = 30;
                break;
            default:
                mm_length = 31;
                break;
        }
    }

    //error checking for leap years
    if (dd > mm_length) {
        printf("\nThe entered date was incorrect 👎\nPlease reboot & try again using the correct format (dd/mm/yyyy).\n\n");
        return 0;
    }

    //calculate tomorrow's date
    dd = dd + 1;
    if ((dd) > mm_length) {
        mm = mm + 1;
        dd = 1;
    }
    if ((mm) > MONTHS_IN_YEAR) {
        mm = 1;
        yyyy = yyyy + 1;
    }

    ///output the current date
    if ((dd) < 10 && (mm) < 10) {
        printf("\nTomorrow: %02d/%02d/%4d\n", dd, mm, yyyy);
    } else if ((dd) < 10) {
        printf("\nTomorrow: %02d/%2d/%4d\n", dd, mm, yyyy);
    } else if ((mm) < 10) {
        printf("\nTomorrow: %2d/%02d/%4d\n", dd, mm, yyyy);
    } else {
        printf("\nTomorrow: %2d/%2d/%4d\n", dd, mm, yyyy);
    }
    
    ///for fun - your birthday (date not my own)
    if ((mm == 2) && (dd==2)) {
        printf("\nHappy Birthday! 🎁\n");
    }

    //for fun - beginning of month messages & new year
    if ((mm == 1) && (dd==1)) {
        printf("\nHappy New Year! 🎉\n");
    } else if ((mm == 12) && (dd==25)) {
        printf("\nIt's Christmas Eve, Merry Christmas! 🎅\n");
    } else if (dd==1) {
        printf("\nHave a great month 👌\n");
    }
    
    newline();
	return 0;
}