/* 
    Triangle - A C Program

    A program that draws a triangle with a number of rows specified by the user.
    Able to set the maximum within the code.

    ✅ Finished

	Peter S. - (https://peter-s.now.sh)
	 * 09/18
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int
main(int argc, char const *argv[])
{
    int rows;
    // Get size (number of rows) to build triangle
    printf("Enter val between 1 and %d: ", MAX);
    if (scanf("%d\n", &rows) != 1) {
        printf("👎 I don't know how many rows you want me to print?\n");
        exit(EXIT_FAILURE);
    }
    // Error checking - positive and less than MAX
    if (rows < 1 || rows > MAX) {
        printf("Sorry 👎 the number of rows must be between 1 and %d\n", MAX);
        exit(EXIT_FAILURE);
    }

    printf("\n△ Generating triangle of size %d...\n\n", rows);

    int sum, i, j;

    //nested loop to print spaces required for whitespace
    // as well as the number of stars per row.
    sum=0;
    for (i=1; i<=rows; i++) {

        for (j = i+1; j<=rows; j++) {
            printf(" ");
        }
        for (j=1;j<2*i-1;j++) {
            printf("*");
        }
        printf("*\n");
        
    }
    printf("\n");
    return 0;
}
