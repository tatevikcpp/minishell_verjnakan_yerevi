/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:01:41 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 21:01:42 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirect *new_t_redirect(char *f_name, int flag)
{
   t_redirect *new_node;

    new_node = malloc(sizeof(t_redirect));
    new_node->f_name = f_name;
    new_node->f_name_backup = f_name;
    new_node->heredoc_fd = -1;
    new_node->flag = flag;
    new_node->next = NULL;
    return (new_node);
}

t_redirect	*ft_t_redirect_last(t_redirect *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_t_redirect_add_back(t_redirect **lst, t_redirect *new)
{
	t_redirect	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_t_redirect_last(*lst);
	new_node->next = new;
}
