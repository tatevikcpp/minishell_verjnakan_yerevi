/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:23:21 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 19:43:47 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_convert(va_list arg, const char form, int fd)
{
	int	lenght;

	lenght = 0;
	if (form == 'c')
		lenght += ft_c(va_arg(arg, int), fd);
	else if (form == 's')
		lenght += ft_s(va_arg(arg, char *), fd);
	else if (form == 'p')
		lenght += ft_p(va_arg(arg, unsigned long long), fd);
	else if (form == 'd' || form == 'i')
		lenght += ft_d(va_arg(arg, int), fd);
	else if (form == 'u')
		lenght += ft_u(va_arg(arg, unsigned int), fd);
	else if (form == 'x')
		lenght += ft_xu(va_arg(arg, unsigned int), fd);
	else if (form == 'X')
		lenght += ft_xl(va_arg(arg, unsigned int), fd);
	else if (form == '%')
		lenght += ft_print_percent(fd);
	return (lenght);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_convert(arg, s[i + 1], fd);
			i++;
		}
		else
			len += ft_c(s[i], fd);
		i++;
	}
	va_end(arg);
	return (len);
}
