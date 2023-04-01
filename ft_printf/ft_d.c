/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:57:33 by tkhechoy          #+#    #+#             */
/*   Updated: 2022/05/27 17:12:50 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_d(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_c('-', fd);
		count += ft_c('2', fd);
		n = 147483648;
	}
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		count += ft_c('-', fd);
	}
	if ((n / 10) > 0)
	{
		count += ft_d(n / 10, fd);
		count += ft_d(n % 10, fd);
		return (count);
	}
	else
		count += ft_c(n + 48, fd);
	return (count);
}
