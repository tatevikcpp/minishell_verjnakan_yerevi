#include "minishell.h"

int check_symbol(char *str)
{
    int i;
    i = 0;
    if(str[i] == '-')
    {
        i++;
        while (str[i] && str[i] == 'n') 
            i++;
        if(str[i] == '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}

void    ft_echo(char **ptr, int fd)
{
    int     i;
    int     flag;

    i = 1;
    flag = 0;
    while(ptr[i])
    {
        if(check_symbol(ptr[i]) == 1 && i <= 1 )
        {
            flag = 1;
            i++;
        }
        else
        {
            
            write(fd, ptr[i], ft_strlen(ptr[i]));
            i++;
            if(ptr[i] && ptr[i + 1] == '\0')
                write(fd, " ", 1);
        }
    }
    if (flag == 0)
        write(fd, "\n", 1);
}
