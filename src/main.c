#include <stdio.h>
#include <stdlib.h>

#ifdef USE_TASK1
#include "static_lib.h"
#endif

#ifdef USE_TASK2
#include "dynamic_lib.h"
#endif


int main()
{
    long long a;

#ifdef USE_TASK2
    char input[256];
#endif

#ifdef USE_TASK1
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

#ifdef USE_TASK2
    printf("\nOperations:\n");
    printf("\
    1) Convert text to UPPERCASE\n\
    2) Convert text to lowercase\n");

    printf("Choose operation number: ");
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
