/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:49:07 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 20:33:27 by adashyan         ###   ########.fr       */
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
