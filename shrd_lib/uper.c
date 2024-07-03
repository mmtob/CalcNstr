#include <stdio.h>
#include <string.h>
#include "static_lib.h"


char * to_uppercase(char * str)
{
    if(!str)
    {
        printf("Empty string\n");
        return NULL;
    }
    char* uppercased_str = strdup(str);

    if(!uppercased_str)
    {
        printf("Failed memory copy\n");
        return NULL;
    }

    for (int i = 0; uppercased_str[i] != '\0'; i++) 
    {
        if (uppercased_str[i] >= 'a' && uppercased_str[i] <= 'z')
        {
            uppercased_str[i] += 'A' - 'a';
        }
    }

    return uppercased_str;
}
