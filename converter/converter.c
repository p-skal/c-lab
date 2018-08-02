/* 
    Unit Converter - A C Program

    Converts unit such as kg to lbs, kilograms to miles, celsius to fahrenheit.
   
    ✅ Finished

	Peter S. - (https://twitter.com/ps300300)
	 * 08/18
*/

#include <stdio.h>
#include <stdlib.h>

//unit definitions
#define FAHRENHEIT 'F'
#define FAHRENHEIT_LOW 'f'
#define CELSIUS 'C'
#define CELSIUS_LOW 'c'
#define MILES 'M'
#define MILES_LOW 'm'
#define KILOMETRES 'K'
#define KILOMETRES_LOW 'k'
#define POUNDS 'P'
#define POUNDS_LOW 'p'
#define KILOGRAMS 'G'
#define KILOGRAMS_LOW 'g'

//calculatio constants
#define DISTANCE_CONSTANT 1.609344
#define MASS_CONSTANT 2.2

//calculation formulae
#define CELSIUS_TO_FAHRENHEIT (val * 9.0/5.0) + 32.0
#define FAHRENHEIT_TO_CELSIUS (val -32) * 5.0/9.0

//testing a function that adds new line by itself
void newline ()  {
    printf("\n");
}

int
main(int argc, char *argv[]) {
	float val, new_val;
    char type;

    //prompts, then scans in magnitude and unit (with error-checking)
    printf("(G=kg, P=lbs, M=miles, K=km, C=celsius, F=fahrenheit)\nEnter the magnitude and units: ");
    if (scanf("%f%c", &val, &type)!=2) {
        printf("❗ ️Please reboot & re-enter the value and units.\n");
        exit(EXIT_FAILURE);
    }
    
    //conditionals that check for unit amd perform appropriate conversion
    if (type == CELSIUS || type == CELSIUS_LOW) {
        new_val = CELSIUS_TO_FAHRENHEIT;
        printf("\n🌡  Temperature %.2f°C converts to %.2f°F\n", val, new_val);
    } else if (type == FAHRENHEIT || type == FAHRENHEIT_LOW) {
        new_val = FAHRENHEIT_TO_CELSIUS;
        printf("\n🌡  Temperature %.2f°F converts to %.2f°C\n", val, new_val);
    } else if (type == MILES || type == MILES_LOW) {
        new_val = (val) / DISTANCE_CONSTANT;
        printf("\n🏃‍   Distance %.2f miles converts to %.2f kilometres\n", val, new_val);
    } else if (type == KILOMETRES || type == KILOMETRES_LOW) {
        new_val = (val) * DISTANCE_CONSTANT;
        printf("\n🏃‍   Distance %.2f kilometres converts to %.2f miles\n", val, new_val);
    } else if (type == KILOGRAMS || type == KILOGRAMS_LOW) {
        new_val = (val) * MASS_CONSTANT;
        printf("\n🏃‍   Distance %.2f kilograms converts to %.2f pounds\n", val, new_val);
    } else if (type == POUNDS || type == POUNDS_LOW) {
        new_val = (val) / MASS_CONSTANT;
        printf("\n🏃‍   Distance %.2f pounds converts to %.2f kilograms\n", val, new_val);
    } else {
        printf("❗ ️Please reboot & specify the units to convert from.\n");
        exit(EXIT_FAILURE);
    }

    newline();
	return 0;
}