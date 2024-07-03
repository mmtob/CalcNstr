#include <stdio.h>
#include <math.h>
#include "static_lib.h"

void sqrt_newton(double number)
{
    double tolerance = 0.00001;
    double guess = number / 2.0;
    double difference;
    double new_guess;

    if (number < 0) {
        printf("Your value is negative, this number is not suitable, better luck next time.\n");
        return;
    }

    do 
    {
        new_guess = (guess + number / guess) / 2.0;
        difference = fabs(new_guess - guess);
        guess = new_guess;
    } while (difference > tolerance);

    printf("sqrt(%lf) = %lf\n", number, guess);
}