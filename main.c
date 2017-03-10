/* 
 * File:   main.c
 * Author: Darilys Pereira
 * Created on January 23, 2016, 7:50 PM
 * 
 * This program produces a temperature conversion char on the range [-20, 280]
 * from Fahrenheit to Celsius and vice versa.
 * The user is prompted to enter the step desired [1-9], this is, the gap  
 * between one conversion to the next one. The user's input is validated and 
 * the corresponding conversions and output are generated. 
 * 
 * "I hereby certify that this collective work is my own.
 * Darilys Pereira Lopez DP.
 */

#include <stdio.h>

//functions prototype
float CelsiustoFahrenheit(float x);
float FahrenheittoCelsius(float y);

//main function

int main(int argc, char** argv) {

    //declaration & initialization
    const int LOWER = -20;
    const int UPPER = 280;
    int inputValFlag = 1;
    int step = 0;
    float celsius = LOWER;
    float fahrenheit = LOWER;
    float celToFar = 0;
    float farToCel = 0;

    //input
    while (inputValFlag != 0) {
        printf("Enter the step desired (1-9):");
        step = getchar();
        step = step - '0'; // convert to number
        getchar(); //absorb the ENTER key

        if (step >= 1 && step <= 9) { //validation of input
            inputValFlag = 0;
        } else {
            printf("Invalid input. Please try again: \n");
        }
    }// end of while loop

    
    //output
    printf("\nFahrenheit         Celsius          Celsius      Fahrenheit \n");
    printf("-------------------------------------------------------------\n");
    while (celsius <= UPPER && fahrenheit <= UPPER) {
        celToFar = CelsiustoFahrenheit(celsius);
        farToCel = FahrenheittoCelsius(fahrenheit);
        printf("%9.1f\t%9.1f\t %9.1f\t %9.1f\t \n", fahrenheit, farToCel,
                celsius, celToFar);
        celsius = celsius + step;
        fahrenheit = fahrenheit + step;
    } // end of while loop

    return 0;
} // end of main function

/*
 * Function: CelsiustoFahrenheit
 * -----------------------------
 * This function converts a give temperature in celsius to fahrenheit
 * Parameter: Celsius degrees in floating point type
 * Returns: This function returns the corresponding fahrenheit value for the
 * given celsius degrees.
 * Side effects: No side effects. All parameters are passed by value. 
 */
float CelsiustoFahrenheit(float celsius) {
    return (celsius * (9 / 5.0)) + 32;
}

/*
 * Function: FahrenheittoCelsius
 * -----------------------------
 * This function converts a give temperature in fahrenheit to celsius 
 * Parameter: Fahrenheit degrees in floating point type
 * Returns: This function returns the corresponding celsius value for the
 * given fahrenheit degrees.
 * Side effects: No side effects. All parameters are passed by value. 
 */
float FahrenheittoCelsius(float fahrenheit) {
    return ( (fahrenheit - 32) * (5 / 9.0));
}