/* 
    Counter - A C Program

    A program that counts the number of characters and words entered.

	Peter S. - (https://peter-s.now.sh)
	 * 08/18
*/

#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
#define NEWLINE '\n'

int
main(int argc, char *argv[]) {
    int c=0;
    char next;
    int num_words=0, num_chars=0, num_newlines=0, num_spaces=0;


    //prompt, then scan checking some data has been entered
    printf("Enter text for counting: ");
    if (scanf("%c", &next)!=1) {
        printf("\nI couldn't find the text 👎\nPlease reboot & enter your text again.\n\n");
        exit(EXIT_FAILURE);
    }
    
    //main calculations - while loop to process each character scanned in
    num_chars++;
    while ((c=getchar()) !=EOF) {
        if (c==NEWLINE) {
            num_newlines++;
        } else if (c==SPACE) {
            num_spaces++;
        } else {
            num_chars++;
        }
        if (c==SPACE || c==NEWLINE) {
            num_words++;
        } 
    }

    //error-checking - empty input
    if (num_words == 0) {
        printf("\nI couldn't find the text 👎\nPlease reboot & enter your text again.\n\n");
        exit(EXIT_FAILURE);
    }

    //combine spaces & characters - both are characters
    num_chars += num_spaces;

    printf("\n-------------------------\n");
    printf(" ‣ Characters: %d\n",num_chars);
    printf("   ‣ Spaces included: %d\n",num_spaces);
    printf(" ‣ Words: %d\n",num_words);
    printf(" ‣ Lines: %d\n",num_newlines);    
    printf("-------------------------\n\n");

    if (num_words > 100) {
        printf("Are you writing a novel? 📕\n\n");  
    } else if (num_words > 30) {
        printf("You must love your writing... 🤓\n\n");   
    } else if (num_words > 10) {
        printf("Almost a paragraph! 🖋\n\n");  
    }

	return 0;
}