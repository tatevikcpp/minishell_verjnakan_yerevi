#include "minishell.h"

int ft_cd(char **argv , t_data *data)
{
    if (!argv[1])
    {
        printf("home\n");
        chdir(ft_get_value("HOME", data));
    }
    else if (chdir(argv[1]) != 0)
        printf("minishell:  %s: %s: No such file or directory\n", argv[0], argv[1]); //ft_printf ? perror ?
    // else
    //     chdir(argv[1]);
    return (0);
}
