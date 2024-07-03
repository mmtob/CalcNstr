#include <stdio.h>
#include "static_lib.h"


void sum_until_zero()
{
    double sum = 0;
    double value = 0;

    printf("Sum (enter 0 for finish input)\n");
    do 
    {
        printf("Enter next value: ");
        scanf("%lf", &value);
        sum += value;
    } 
    while(value);

    printf("Your answer is: %lf\n", sum);
}