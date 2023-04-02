/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:17:25 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 11:25:31 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	check_errors(char *ptr)
// {
// 	int	i;

// 	i = 0;
// 	while (ptr[i])
// 	{
// 		if (metachar_error(ptr) == 1)
// 			return (1);
// 		if (syntax_error(ptr, i) == 1)
// 			return (1);
// 		if (metachar_error(ptr) == 1)
// 			return (1);
// 		if (ptr[i])
// 			i++;
// 	}
// 	return (0);
// }

int	check_quote_double(char *ptr)
{
	int		i;
	char	c;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == '\'')
		{
			c = ptr[i++];
			while (ptr[i] && ptr[i] != c)
				++i;
			if (ptr[i] == '\0')
			{
				ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	valid_redirect(char *ptr);

int	check_errors(char *ptr)
{
	if (valid_redirect(ptr) != 0)
		return (258);
	// if (valid_pipe(ptr) != 0)
	// 	return (258);
	return (0);
}
// ">> askhdc"">>auisfh"
int	valid_redirect(char *ptr)
{
	int	i;
	int j;

	i = 0;
	while (ptr[i])
	{
		// printf("before\n");
		// printf("ptr[i] = %c\n", ptr[i]);
		// printf("ptr[i] = %d\n", i);
		i = for_space(ptr, '\'', i);
		i = for_space(ptr, '"', i);
		// printf("after\n");
		// printf("ptr[i] = %c\n", ptr[i]);
		// printf("ptr[i] = %d\n", i);
		while (ptr[i] && ft_strchr(SPACES, ptr[i]))
			i++;
		if (is_redirect_in(ptr[i]) || is_redirect_out(ptr[i]))
		{
			i++;
			if (is_append_in(ptr[i - 1], ptr[i]) || is_append_out(ptr[i - 1], ptr[i]))
				i++;
			while (ptr[i] && ft_strchr(SPACES, ptr[i]))
				i++;
			j = i;
			while (ptr[i] && !ft_strchr(METACHARACTER, ptr[i]))
				++i;
			// printf("j = %d\n", j);
			// printf("i = %d\n", i);
			if (i == j)
			{
				ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
				return (1);	
			}
			// while (ft_isalpha(ptr[i] || ft_isalnum(ptr[i])))
			// 	i++;		
		}
		if (ptr[i] && ptr[i] != '"' && ptr[i] != '\'')
			++i;
	}
	return (0);
}

// int	is_there_word(char *str, char *start_str)
// {
// 	int	i;

// 	i = 0;
// 	i--;
// 	while (ptr[i] && ft_strchr(SPACES, ptr[i]))
// 		i++;
// 	while ((&str[i] != &start_str[i]) && !ft_strchr(METACHARACTER, str[i]))
// 		i--;
	
// }

// int	valid_pipe(char *ptr)
// {
// 	int	i;

// 	i = 0;
// 	while (ptr[i])
// 	{
// 		while (ptr[i] && ft_strchr(SPACES, ptr[i]))
// 			i++;
// 		while (ptr[i] && ptr[i] != '|')
// 			i++;
// 		if (ptr[i] == '|')
// 		{
			
// 		}
// 	}
// }