/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:49:07 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 20:29:56 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_t_env(char *tmp, char *tmp1)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	new_node->key = ft_strdup(tmp);
	new_node->val = ft_strdup(tmp1);
	new_node->next = NULL;
	return (new_node);
}

t_env	*ft_t_env_last(t_env *lst)
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

int	replace_env(t_env *lst, t_env *new)
{
	while (lst)
	{
		if (ft_strcmp(lst->key, new->key) == 0)
		{
			free(lst->val);
			lst->val = new->val;
			free(new->key);
			free(new);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void	ft_t_env_add_back(t_env **lst, t_env *new)
{
	t_env	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (replace_env(*lst, new) == 1)
		return ;
	new_node = ft_t_env_last(*lst);
	new_node->next = new;
}
