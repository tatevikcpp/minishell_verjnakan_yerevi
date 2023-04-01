/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:15:13 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/22 18:44:14 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_count(long long int n, const char *base, int fd)
{
	int	count;

	count = 0;
	if (n >= ft_strlen_ft(base))
		count += ft_nbr_count((n / ft_strlen_ft(base)), base, fd);
	count += write(fd, &base[n % ft_strlen_ft(base)], 1);
	return (count);
}
