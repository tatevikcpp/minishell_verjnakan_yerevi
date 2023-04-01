/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:17:45 by sokhacha          #+#    #+#             */
/*   Updated: 2023/03/24 12:03:53 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc((i + j + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	if (s1)
	{
		while (s1 && *s1 != '\0')
			*ptr++ = *s1++;
	}
	if (s2)
	{
		while (s2 && *s2 != '\0')
			*ptr++ = *s2++;
	}
	*ptr = '\0';
	return (ptr - i - j);
}
