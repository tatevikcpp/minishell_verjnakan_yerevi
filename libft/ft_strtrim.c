/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:11:05 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/02 13:11:06 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_char_in_set(char c, char const *set)
// {
// 	size_t	i;

// 	i = 0;
// 	while (set[i])
// 	{
// 		if (set[i] == c)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*str;
// 	size_t	i;
// 	size_t	start;
// 	size_t	end;

// 	end = 0;
// 	while (s1[end])
// 		end++;
// 	start = 0;
// 	while (s1[start] && ft_char_in_set(s1[start], set))
// 		start++;
// 	while (end > start && ft_char_in_set(s1[end - 1], set))
// 		end--;
// 	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (start < end)
// 		str[i++] = s1[start++];
// 	str[i] = 0;
// 	return (str);
// }

int	find_first(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (set[++j] && s1[i])
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j = -1;
			i++;
		}
	}
	return (i);
}

int	find_last(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = ft_strlen(s1) - 1;
	j = -1;
	count = 0;
	while (set[++j] && s1[i])
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j = -1;
			i--;
			count++;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		first;
	int		last;

	if (s1 && set)
	{
		first = find_first(s1, set);
		last = find_last(s1, set);
		ptr = ft_substr(s1, first, ft_strlen(s1) - first - last);
		return (ptr);
	}
	else
		return (ft_strdup(s1));
	return (0);
}
