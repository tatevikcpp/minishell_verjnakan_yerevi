/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:00:08 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 21:37:17 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjon_free_arg1(char *s1, char const *s2)
{
	char	*ptr;
	char	*ptr_free;
	size_t	i;
	size_t	j;

	ptr_free = s1;
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
	free(ptr_free);
	return (ptr - i - j);
}

char	*ft_strjon_free_arg2(char const *s1, char *s2)
{
	char	*ptr;
	char	*ptr_free;
	size_t	i;
	size_t	j;

	ptr_free = s2;
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
	free(ptr_free);
	return (ptr - i - j);
}

char	*ft_strjon_free_both(char *s1, char *s2)
{
	char	*ptr;
	char	*ptr_free_s1;
	char	*ptr_free_s2;
	size_t	i;
	size_t	j;

	ptr_free_s1 = s1;
	ptr_free_s2 = s2;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)ft_calloc((i + j + 1), sizeof(char));
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
	free(ptr_free_s1);
	return (free(ptr_free_s2), ptr - i - j);
}
