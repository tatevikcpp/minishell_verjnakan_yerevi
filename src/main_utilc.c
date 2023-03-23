#include "minishell.h"

int  for_space(char *ptr, char c, int i)
{
    if (ptr[i] == c)
    {
        i++;
        while(ptr[i] && ptr[i] != c)
            i++;
        if (ptr[i])
            i++;
    }
    return (i);
}