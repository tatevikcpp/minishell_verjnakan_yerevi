/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:02:56 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/02 21:41:50 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	d;

	d = c;
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((char)str[i] == (char)d)
			return (str + i);
		i++;
	}
	return (NULL);
}
