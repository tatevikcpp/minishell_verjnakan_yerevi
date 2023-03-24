/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_to_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:44:36 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/23 20:49:56 by tkhechoy         ###   ########.fr       */
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

// ls">" asfas
int	redirect_to_command(t_pipe *top, int *i)
{
	int k;
	char *tmp_comand;
	
	k = 0;
	// if (top->content[*i] == '\'')
	// 	redirect_to_quote(top,  i, '\'');
	// else if (top->content[*i] == '"')
	// {
	// 	// printf("else\n");
	// 	redirect_to_quote(top,  i, '"');
	// }
	k = (*i);
	// if (top->content[*i] == '$' && (ft_isalpha(top->content[*i + 1]) || top->content[*i + 1] == '_'))
	// 	top->s = ft_strjoin(top->s, hendl_dolar(top, top->content, i));
    // printf("redirect_to_command\n");
	while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
	{
		*i = for_space(top->content, '\'', *i);
		*i = for_space(top->content, '"', *i);
		if (top->content[*i]  && !ft_strchr(METACHARACTER, top->content[*i]))
			(*i)++;
		// printf("cont : %s\n", top->content + *i);
	}
	tmp_comand = ft_substr(top->content, k, *i - k + 1);
	// if (tmp_comand[0] != '$')
		top->s = ft_strjoin(top->s, ft_strtrim(tmp_comand, METACHARACTER));
	top->s = ft_strjoin_ft(top->s, 42);
	// printf("top->s: %s\n", top->s);
	// if (top->content[*i])
	// 	(*i)++;
	return (1);
}
