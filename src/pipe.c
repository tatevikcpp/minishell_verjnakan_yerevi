/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:38 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 20:01:50 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// //  |$ls|"$ls   "|a

void split_string(char *input, t_data *data)
{
	int		i;
	int		k;
	int		flag_for_null;

	i = 0;
	k = 0;
	data->pipe_count = 1;
	while (input[i])
	{
		flag_for_null = 0;
		i = for_space(input, '"', i);
		i = for_space(input, '\'', i);
		if (i != 0 && (input[i] == '|' || input[i + 1] == '\0'))
		{
			if (input[i + 1] != '\0' || (input[i + 1] == '\0'
				&& input[i] == '|')) 
				input[i] = flag_for_null++;
			ft_lstadd_back(&data->pipe,  ft_lstnew(&input[k], data->head_env));
			k = i + 1;
			if (flag_for_null == 1 && ++i)
				data->pipe_count++;
		}
		if (flag_for_null != 1 && input[i] && ft_strchr("'\"", input[i]) == 0)
			i++;
	}
}
