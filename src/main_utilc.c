/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:49:07 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 21:38:23 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	for_space(char *ptr, char c, int i)
{
	if (ptr[i] == c)
	{
		i++;
		while (ptr[i] && ptr[i] != c)
			i++;
		if (ptr[i])
			i++;
	}
	return (i);
}

bool	is_append_out(char c, char d)
{
	return ((c == '>' && d == '>'));
}
