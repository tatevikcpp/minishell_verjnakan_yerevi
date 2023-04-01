/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:17:25 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 09:40:22 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int pipe_error(char *ptr)
{
    int i;

    i = 0;
    while (ptr && ptr[i] <= 32)
        i++;
    if (ptr[i] && ptr[i] == '|')
    {
        ft_printf(2, "minishell: syntax error near unexpected token `|'");
        return (1);
    }
    while (ptr && ptr[i])
    {
        while (ptr && ptr[i] && ptr[i] != '|')
            i++;
        if (ptr && ptr[i] && ptr[i] == '|')
        {
            ft_printf(2, "minishell: syntax error near unexpected token `|'");
            return (1);
        }
        i++;
    }
    return (0);
}