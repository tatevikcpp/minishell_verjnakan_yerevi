/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:53:16 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 16:53:41 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_symbol(char **str, int *k)
{
	int i;
	int j;
	int flag;

	i = 1;
	flag = 0;
	while (str && str[i])
	{
		j = 0;
		if (str[i][j] == '-')
		{
			j++;
			while (str[i][j] == 'n')
				j++;
			if (str[i][j] != '\0')
				return (*k = i, flag);
			flag = 1;
		}
		else
			return (*k = i, flag);
		i++;
	}
	return (*k = i, flag);
}

void    ft_echo(char **ptr, int fd)
{
	int     i;
	int     flag;

	i = 1;
	flag = 0;
	
	if(check_symbol(ptr, &i) == 1)
		flag = 1;
	while(ptr[i])
	{
		write(fd, ptr[i], ft_strlen(ptr[i]));
		i++;
		if(ptr[i])
			write(fd, " ", 1);
	}
	if (flag == 0)
		write(fd, "\n", 1);
}
