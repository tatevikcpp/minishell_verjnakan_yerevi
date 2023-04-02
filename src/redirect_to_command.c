/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_to_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:44:36 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/02 10:48:20 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_ft(char const *s1, char c)
{
	char	*ptr;
	int		k;

	k = ft_strlen(s1);
	ptr = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		*ptr++ = *s1++;
	if (c)
		*ptr++ = c;
	*ptr = '\0';
	return (ptr - k - 1);
}

int	redirect_to_command(t_pipe *top, int *i)
{
	int		k;
	char	*tmp_1;	
	char	*tmp_comand;

	k = 0;
	k = (*i);
	while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
	{
		*i = for_space(top->content, '\'', *i);
		*i = for_space(top->content, '"', *i);
		if (top->content[*i] && top->content[*i] != '"' && top->content[*i] != '\''
			&& !ft_strchr(METACHARACTER, top->content[*i]))
			(*i)++;
	}
	tmp_comand = ft_substr(top->content, k, *i - k + 1);
	tmp_1 = ft_strtrim(tmp_comand, METACHARACTER);
	free(tmp_comand);
	top->joined_argv = ft_strjon_free_arg1(top->joined_argv, tmp_1);
	free(tmp_1);
	tmp_1 = top->joined_argv;
	top->joined_argv = ft_strjoin_ft(top->joined_argv, 1);
	free(tmp_1);
	return (1);
}
