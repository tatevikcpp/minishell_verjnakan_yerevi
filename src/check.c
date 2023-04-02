/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:17:25 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 21:21:58 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_there_word_before(char *str, char *start_str)
{
	int	i;

	i = 0;
	i--;
	while (&str[i] != start_str && ft_strchr(SPACES, str[i]))
		i--;
	if (!ft_strchr("|&;() ", str[i]))
		return (1);
	return (0);
}

static int	is_there_word_after(char *str)
{
	int	i;

	i = 0;
	i++;
	while (str[i] && ft_strchr(SPACES, str[i]))
		i++;
	if (!ft_strchr("|&;()", str[i]))
		return (1);
	return (0);
}

static int	valid_pipe(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i = for_space(ptr, '"', i);
		i = for_space(ptr, '\'', i);
		while (ptr[i] && ptr[i] != '"' && ptr[i] != '\'' && ptr[i] != '|')
			i++;
		if (ptr[i] == '|')
		{
			if (i == 0 || !is_there_word_before(&ptr[i], ptr)
				|| !is_there_word_after(&ptr[i]))
			{
				ft_printf(2, "minishell: syntax error near unexpected\
 token `|'\n");
				return (1);
			}
		}
		if (ptr[i] && ptr[i] != '"' && ptr[i] != '\'')
			i++;
	}
	return (0);
}

int	check_errors(char *ptr)
{
	if (valid_redirect(ptr) != 0)
		return (258);
	if (valid_pipe(ptr) != 0)
		return (258);
	return (0);
}
