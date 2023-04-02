/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:21:03 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 12:22:40 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_redirect_helper(char *ptr, int *i)
{
	int	j;

	while (ptr[(*i)] && ft_strchr(SPACES, ptr[(*i)]))
		(*i)++;
	j = (*i);
	while (ptr[(*i)] && !ft_strchr(METACHARACTER, ptr[(*i)]))
		++(*i);
	if ((*i) == j)
	{
		ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
		return (1);
	}
	return (0);
}

int	valid_redirect(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i = for_space(ptr, '\'', i);
		i = for_space(ptr, '"', i);
		while (ptr[i] && ft_strchr(SPACES, ptr[i]))
			i++;
		if (is_redirect_in(ptr[i]) || is_redirect_out(ptr[i]))
		{
			i++;
			if (is_append_in(ptr[i - 1], ptr[i])
				|| is_append_out(ptr[i - 1], ptr[i]))
				i++;
			if (valid_redirect_helper(ptr, &i) != 0)
				return (1);
		}
		if (ptr[i] && ptr[i] != '"' && ptr[i] != '\'')
			++i;
	}
	return (0);
}
