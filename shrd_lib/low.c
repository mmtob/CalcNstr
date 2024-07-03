#include <stdio.h>
#include <string.h>
#include "static_lib.h"


char * to_lowercase(char * str)
{
    if(!str)
    {
        printf("Empty string\n");
        return NULL;
    }
    char* lowercased_str = strdup(str);

    if(!lowercased_str)
    {
        printf("Failed memory copy\n");
        return NULL;
    }

    for (int i = 0; lowercased_str[i] != '\0'; i++) 
    {
        if (lowercased_str[i] >= 'A' && lowercased_str[i] <= 'Z')
        {
            lowercased_str[i] += 'a' - 'A';
        }
    }

    return lowercased_str;
}
