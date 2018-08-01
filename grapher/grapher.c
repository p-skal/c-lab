/* 
    Grapher - A C Program

    A program that reads a sequence of integers and draws a simple graph
    Assumes all values read are between 1 and 70.

	Peter S. - (https://twitter.com/ps300300)
	 * 08/18
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 70
#define MIN_VAL 1

//testing a function that adds new line by itself
void newline ()  {
    printf("\n");
}

int
main(int argc, char *argv[]) {
	int next, vals_read;
    //array of size of max value
    int vals[MAX_VAL];
    int i;

    //prompt, then scan checking some data has been entered
    printf("Enter numbers (1-70, control-D to end): ");
    if (scanf("%d", &next)!=1) {
        printf("\nNo data found 👎\nPlease reboot & enter your data again.\n\n");
        exit(EXIT_FAILURE);
    }

    //check if number is between 1 and 70 (inclusive)
    if (scanf("%d", &next)<MIN_VAL || scanf("%d", &next)>MAX_VAL) {
        printf("\nInvalid 👎\nPlease reboot & enter numbers between 1 and 70 (inclusive).\n\n");
        exit(EXIT_FAILURE);
    }
    
    //initializes first number scanned
    vals_read = 1;
    vals[0] = next;

	//Scan further values and add each to vals array, while updating the total number of vals
	while (scanf("%d", &next)==1) {
        vals[vals_read] = next;
        vals_read += 1;
	}
	/* printf("%d values read\n", vals_read); TESTING */

    newline();
    printf("📊  Generating Graph...");
    newline();newline();

    printf("\n%d\n", vals_read);
    //loops through each val, printing it and then performing a nested loop that prints 'val * "*"'
    for (i=0; i<vals_read; i=i+1) {
        //adds space if val <2 digits (for aesthetics 😉)
        if (vals[i] < 10) {
            printf(" %d | ", vals[i]);
        } else {
            printf("%d | ", vals[i]);
        }
        int j;
        for (j=0; j<=vals[i]; j=j+1) {
            printf("*");
        }
        newline();
    }

    printf("\nGraph generated successfully ✅\n");
    
    newline();
	return 0;
}