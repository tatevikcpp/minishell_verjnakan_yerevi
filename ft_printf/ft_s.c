/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:45:24 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/22 18:44:06 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *s, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		count += ft_s("(null)", fd);
	else
		while (s[i] != '\0')
			count += write(fd, &s[i++], 1);
	return (count);
}
