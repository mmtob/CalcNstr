#include <stdio.h>
#include "static_lib.h"


void multiply_until_one()
{
    double result = 1;
    double value = 1;

    printf("Multiply (enter 1 for finish input)\n");
    do 
    {
        printf("Enter next value: ");
        scanf("%lf", &value);
        result *= value;
    } 
    while(value != 1);

    printf("Your answer is: %lf\n", result);
}