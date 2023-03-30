#include "minishell.h"

extern int exit_status;

char *access_path(t_data *data, char **args)
{
	char    **split_path;
    int     i;
    char    *str;
    char    *exe;

    i = 0;
    if (access(args[0], F_OK) == 0)
        return (args[0]);
    exe = ft_strjoin("/", args[0]);
    split_path = ft_split(ft_get_value("PATH", data), ':');
    while (split_path[i])
    {
        str = ft_strjoin(split_path[i], exe);
        if(access(str, F_OK) == 0)
        {
            free(exe);
            return(str);
        }
        free(str);
        i++;
    }
    free(exe);
    return(args[0]);
}

int lsh_launch(t_data *data, t_pipe *pipe)
{
	char    **args;
    char    *path;
    if (there_is_builtin(data) == 1)
    {
        printf("welcome to built-ins\n");
        exit (choose_builtin(/* ptr, */ data->pipe, data));
    }
    args = pipe->argv;
    path = access_path(data, args);
    printf("path = %s\n", path);
	if(execve(path, args, data->env) == -1)
    {
		ft_printf(2, "minishell: %s: %s\n", args[0], strerror(errno));
        exit(127);
    }
	return (1);
}

int execute(t_data *data)
{
    if (data->pipe_count == 1 && there_is_builtin(data) == 1)
        return (choose_builtin(/* ptr, */ data->pipe, data));
    else
        return (pipe_exec(data));
    return (0);
}