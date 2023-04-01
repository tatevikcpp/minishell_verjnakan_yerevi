/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:07:25 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/22 18:52:24 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xu(unsigned int n, int fd)
{
	int	count;

	count = 0;
	count += ft_nbr_count(n, "0123456789abcdef", fd);
	return (count);
}
