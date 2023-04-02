/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exit_status_in_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:35:33 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 13:22:25 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_exit_status_in_env(t_data *data, int status)
{
	char	*tmp;

	tmp = ft_itoa(status);
	ft_t_env_add_back(&data->head_env, new_t_env("?", tmp));
	free(tmp);
	return (1);
}
