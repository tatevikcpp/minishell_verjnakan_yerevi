/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:36:58 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 18:28:03 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int strcmp_env(char *str, char **argv) // env-i pahy poxel
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (argv && argv[i])
	{
		if (ft_strcmp(str, argv[i]) == 0)
			flag++;
		i++;
	}
	if (flag == i)
		return (0);
	return (1);
}


int choose_builtin(t_pipe *pipe , t_data *data, int fd)
{
	if (ft_strcmp("export", pipe->argv[0]) == 0)
		return(builtin_export(pipe, fd));
	else if (ft_strcmp("echo", pipe->argv[0]) == 0)
	   return(ft_echo(pipe->argv, fd), 0);
	else if (ft_strcmp("cd", pipe->argv[0]) == 0)
	   return(ft_cd(pipe->argv , data));
	else if (ft_strcmp("exit", pipe->argv[0]) == 0)
		return (ft_exit(pipe->argv, data));
	else if (ft_strcmp("pwd", pipe->argv[0]) == 0)
	   return (ft_pwd(fd));
	else if (strcmp_env("env", pipe->argv) == 0)
	   return(buildin_env_all(pipe, fd), 0);
	else if (ft_strcmp("unset", pipe->argv[0]) == 0)
		return(ft_list_remove_if(pipe, ft_strcmp));
	return (0);
}
