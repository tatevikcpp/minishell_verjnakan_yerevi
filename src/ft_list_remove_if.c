/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:38:57 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 21:40:10 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_else_inner(t_pipe *pipe, char **str1)
{
	t_env	*head;
	t_env	*new;
	t_env	*tmp;

	head = pipe->head_env;
	if (head == NULL)
		return ;
	if (head && ft_strcmp(head->key, str1[0]) == 0)
	{
		new = head;
		head = head->next;
		free(new);
	}
	new = head;
	while (new && new->next)
	{
		if (ft_strcmp(new->next->key, str1[0]) == 0)
		{
			tmp = new->next;
			new->next = tmp->next;
			free(tmp);
		}
		new = new->next;
	}
}

int	ft_list_remove_if(t_pipe *pipe, int (*ft_strcmp)())
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (pipe->argv[i])
	{
		if (hendl_export_var(pipe->argv[i]) != 0)
		{
			ret = 1;
			ft_printf(2, "minishell:  %s `%s' not a valid identifier\n",
				pipe->argv[0], pipe->argv[i++]);
			continue ;
		}
		remove_else_inner(pipe, &pipe->argv[i]);
		i++;
	}
	return (ret);
}
