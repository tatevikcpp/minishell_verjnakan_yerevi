/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:37:49 by sokhacha          #+#    #+#             */
/*   Updated: 2023/03/31 16:00:35 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*new;
	int		i;

	i = 0;
	while (s1 && s1[i])
		i++;
	new = (char *)ft_calloc((i + 1), sizeof(char));
	if (new == NULL)
		return (0);
	if (!s1)
		return (new);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
