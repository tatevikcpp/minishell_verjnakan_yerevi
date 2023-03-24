// #include "minishell.h"

// char *access_path(t_data *data, char **args)
// {
//     ;
// 	char **split_path;
//     int i;
//     char *str;
//     char *exe;

//     i = 0;  
//     exe = ft_strjoin("/", args[0]);
//     split_path = ft_split(ft_get_value("PATH", data), ':');
//     while (split_path[i])
//     {
//         str = ft_strjoin(split_path[i], exe);
//         if(access(str, F_OK)==0)
//         {
//             free(exe);
//             return(str);
//         }
//         free(str);
//         i++;
//     }
//     free(exe);
//     return(NULL);
// }

// int lsh_launch(t_data *data, t_pipe *pipe)
// {
// 	// char *ptr = "pwd";
// 	char **args;
//     args = pipe->argv;
// 	// args = ft_split(ptr, ' ');
// 	// while(args[i])
// 	// {
// 	// int i = 0;
// 	// 	printf("hello%d, %s\n", i, args[i]);
// 	// 	i++;
// 	// }
//     dup2(data->fd_herdoc, 0);
//    // printf("ok\n");
//     printf("%s --- %s\n", access_path(data, args), args[0]);
// 	if(execve(access_path(data, args), args, data->env) == -1)
// 		perror("Could not execve");
// 	return (1);
// }


// void execute(t_data *data, char *ptr)
// {
//     if (data->pipe_count > 1)
//     {
//     	pipe_exec(data);
//     }
//     else if(data->pipe_count == 1)
//     {
//     	if (ther_is_buildin(data, ptr) == 0)
//     		split_readline(ptr, data->pipe, data);
//     	else
//     	{
//     		pipe_exec(data);
//     	}		
//     }
// }