/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:17:25 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 20:44:21 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_error(char *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i] <= 32)
		i++;
	if (ptr[i] && ptr[i] == '|')
	{
		ft_printf(2, "minishell: syntax error near unexpected token `|'");
		return (1);
	}
	while (ptr && ptr[i])
	{
		while (ptr && ptr[i] && ptr[i] != '|')
			i++;
		if (ptr && ptr[i] && ptr[i] == '|')
		{
			ft_printf(2, "minishell: syntax error near unexpected token `|'");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_errors(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (metachar_error(ptr) == 1)
			return (1);
		if (syntax_error(ptr, i) == 1)
			return (1);
		if (metachar_error(ptr) == 1)
			return (1);
		if (ptr[i])
			i++;
	}
	return (0);
}

int	check_quote_double(char *ptr)
{
	int		i;
	char	c;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == '\'')
		{
			c = ptr[i++];
			while (ptr[i] && ptr[i] != c)
				++i;
			if (ptr[i] == '\0')
			{
				ft_printf(2, "minishell: syntax error near unexpected\
				token `newline'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
