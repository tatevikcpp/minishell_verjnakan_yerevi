/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:04:07 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 20:06:00 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirect	*redirect_test(t_pipe *pipe)
{
	int 		i;
	t_pipe 		*top;
	t_redirect	*head;

	i = 0;
	top = pipe;
	head = NULL;
	while (top->content[i] != '\0')
	{
		while (top->content[i] && top->content[i] <= 32)
			i++;
		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
		{
			redirect_f_name_flag(top, &head, &i);
		}
		else
			redirect_to_command(top, &i);
		if (top->content[i] && !(is_redirect_in(top->content[i])
			|| is_redirect_out(top->content[i])))
			i++;
	}
	return (head);
}

int	get_flag(char *str, int i)
{
	if (str[i] == '>' && str[i + 1] == '>')
		return (O_APPEND);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '<')
		return (O_RDONLY);
	else if (str[i] == '>')
		return (O_TRUNC);
	return (-1);
}

int	redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i)
{
	int		flag;
	int		start;

	flag = get_flag(top->content, (*i)++);
	if (flag == HEREDOC || flag == O_APPEND)
		(*i)++;
	while (is_space(top->content[*i]))
		(*i)++;
	
	start = *i;
	while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
	{
		*i = for_space(top->content, '\'', *i);
		*i = for_space(top->content, '"', *i);
		if(top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
			(*i)++;
	}
	ft_t_redirect_add_back(head, new_t_redirect(
		ft_substr(top->content, start, *i - start), flag));
	*i -= 1;
	if (top->content[*i])
		(*i)++;
	return (0);
}

void	split_s__to_argv( t_data *data,  t_pipe *pipe)
{
	char *for_free;

	for_free = pipe->joined_argv;
	if (pipe->joined_argv)
	{
		pipe->joined_argv = hendl_doloar_comand(data, pipe->joined_argv);
		free(for_free);
		pipe->argv = ft_split(pipe->joined_argv, 1);
		if (pipe->argv[0] == NULL)
			pipe->argv[0] = ft_strdup("");
	}
}


