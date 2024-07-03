#include <stdio.h>
#include <stdlib.h>

#include "static_lib.h"
#include "dynamic_lib.h"


int main()
{
    long long a;


#if defined(USE_TASK2) || defined(USE_TASK3)
    char input[256];
#endif


#if defined(USE_TASK1) || defined(USE_TASK3)

    double d;

    printf("\nOperations:\n");
    printf("\
    1) + sum\n\
    2) - difference\n\
    3) * multiply\n\
    4) / divide\n\
    5) ! factorial\n\
    6) sqrt() square root\n");
    
    printf("Choose operation, enter number: ");
    scanf("%Ld", &a);
    switch(a){
        case 1: sum_until_zero(); break;
        case 2: difference(); break;
        case 3: multiply_until_one(); break;
        case 4: divide(); break;
        case 5: 
        printf("Please enter number [0,25]: ");
        scanf("%Ld", &a);
        a = factorial(a);
        if(a)
        {
            printf("Your factorial is: %Ld\n", a);
        }
        break;

        case 6: 
        printf("Please enter number: ");
        scanf("%lf", &d);
        sqrt_newton(d);
        break;

        default: printf("I`m sooooooooo sorry i don`t know this command!\n");
    }
#endif


#if defined(USE_TASK2) || defined(USE_TASK3)

    
    

    printf("\nOperations:\n");
    printf("\
    1) Convert text to UPPERCASE\n\
    2) Convert text to lowercase\n");

    printf("Choose operation, enter number: ");
    scanf("%Ld", &a);
    printf("Now enter your string: ");
    scanf(" %[^\n]%*c", input);
    switch(a){
        case 1: printf("%s\n", to_uppercase(input)); break;
        case 2: printf("%s\n", to_lowercase(input)); break;
        default: printf("I`m sooooooooo sorry i don`t know this command!\n");
    }

#endif



    return 0;
}