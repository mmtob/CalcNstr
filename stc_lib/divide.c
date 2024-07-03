#include <stdio.h>
#include "static_lib.h"


void divide()
{
    double n1;
    double n2;

    printf("Divide the first number by the second\n");
    printf("Please enter first number: ");
    scanf("%lf", &n1);
    printf("Please enter second number: ");
    scanf("%lf", &n2);
    if(!n2)
    {
        printf("Your try divide by ZERO! No! No! No!");
        return;
    }

    printf("Your answer is: %lf\n", n1 - n2);
}