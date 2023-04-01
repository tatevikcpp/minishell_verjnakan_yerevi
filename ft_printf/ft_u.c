/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:19:11 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/22 18:50:26 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 10)
	{
		n += 48;
		count += ft_c(n, fd);
	}
	else
	{
		count += ft_u(n / 10, fd);
		n = n % 10 + 48;
		count += ft_c(n, fd);
	}
	return (count);
}
