#include <stdio.h>
#include "static_lib.h"


void difference()
{
    double n1;
    double n2;

    printf("Subtract the second from the first number\n");
    printf("Please enter first number: ");
    scanf("%lf", &n1);
    printf("Please enter second number: ");
    scanf("%lf", &n2);

    printf("Your answer is: %lf\n", n1 - n2);
}