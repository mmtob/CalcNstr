#include <stdio.h>
#include "static_lib.h"


long long factorial(long long n)
{
    if (n < 0)
    {
        printf("You enter wrong value\n");
        return 0;
    }
    if(n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
