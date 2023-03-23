#include "minishell.h"

int  for_space(char *ptr, char c, int i)
{
    if (ptr[i] == c)
    {
        i++;
        while(ptr[i] != c)
            i++;        
    }   
    i++;
    return (i);
}