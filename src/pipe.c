/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:41:38 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/23 14:01:18 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//  |$ls|"$ls   "|a

void split_string(char *input, t_data *data)
{
	int		i;
	int		k;
	int		flag_for_null;
	t_pipe	*node;

	i = 0;
	k = 0;
	while (input[i])
	{
		flag_for_null = 0;
		// if(input[i] == '"')
			i = for_space(input, '"', i);
		// if(input[i] == '\'')
			i = for_space(input, '\'', i);
		if (i != 0 && (input[i] == '|' || input[i + 1] == '\0'))
		{
			if (input[i + 1] != '\0' || (input[i + 1] == '\0' && input[i] == '|'))  // krchatel 3 tox 
			{
				input[i] = '\0';
				flag_for_null = 1;
			}
			node = ft_lstnew(&input[k], data->head_env);
			ft_lstadd_back(&data->pipe, node);
			k = i + 1;
			if (flag_for_null == 1)
				i++;
		}
		if (flag_for_null != 1 && input[i] && ft_strchr("'\"", input[i]) == 0)
			i++;
	}
}


void print_lists(t_pipe *red)
{
	t_pipe *head;

	head = red;
	while (head)
	{
		printf("content: %s\n", head->content);
		head = head->next;
	}
}
