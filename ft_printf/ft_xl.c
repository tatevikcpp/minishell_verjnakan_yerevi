/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:59:46 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/22 18:53:25 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xl(unsigned int n, int fd)
{
	int	count;

	count = 0;
	count += ft_nbr_count(n, "0123456789ABCDEF", fd);
	return (count);
}
