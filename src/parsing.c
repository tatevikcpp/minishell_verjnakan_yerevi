/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:49:07 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 21:14:57 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void printf_pipe(t_pipe *pipe);

int open_out_files(t_pipe *pipe, t_redirect *head_red)
{
	if (pipe->fd_out != 1)
		close(pipe->fd_out);
	if (head_red->f_name == NULL)
		return (ft_printf(2, "minishell: %s: ambiguous redirect\n",
			head_red->f_name_backup), 1);
	pipe->fd_out = open(head_red->f_name, O_CREAT
		| head_red->flag | O_WRONLY, 0644);
	if (pipe->fd_out == -1)
		return (ft_printf(2, "minishell: open: %s: %s\n",
			head_red->f_name, strerror(errno)), 1);
	return (0);
}

int open_in_files(t_pipe *pipe, t_redirect *head_red)
{
	if (pipe->fd_in != 0)
		close(pipe->fd_in);
	if (head_red->f_name == NULL)
		return (ft_printf(2, "minishell: %s: ambiguous redirect\n",
			head_red->f_name_backup), 1);
	pipe->fd_in = open(head_red->f_name, head_red->flag);
	if (pipe->fd_in == -1)
		return (ft_printf(2, "minishell: open: %s: %s\n",
			head_red->f_name, strerror(errno)), 1);
	return (0);
}

int open_files_for_redirect (t_pipe *pipe)
{
	t_redirect *head_red;

	head_red = pipe->red;
	while (head_red)
	{
		if (head_red->flag == O_RDONLY)
		{
			if (open_in_files(pipe, head_red) != 0)
				return (1);
		}
		else if (head_red->flag == O_TRUNC || head_red->flag == O_APPEND)
			if (open_out_files(pipe, head_red) != 0)
				return (1);
		if (head_red->flag == HEREDOC)
		{
			if (pipe->fd_in != 0)
				close(pipe->fd_in);
			pipe->fd_in = head_red->heredoc_fd;
		}
		head_red = head_red->next;
	}
	return (0);
}

int check_errors(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		if (metachar_error(ptr) == 1 ) //  > a   - ?
			return (1); //continue
		if (syntax_error(ptr, i) == 1)
		   return (1); //continue
		if (metachar_error(ptr) == 1)
		   return (1);	//continue  // kara chlini
		// check_qoutes(ptr); // sxala ashxatum
		// check_quot_double(ptr);
		// check_quot_one(ptr);
		if (ptr[i])
			i++;
	}
	return (0);
}


// int check_quotes()

int	check_quote_double(char *ptr)
{
	int i;
	char c;

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

void expand_redirect_dollar(t_data *data, t_redirect *tmp)
{
	while (tmp)
	{
		if (tmp->flag != HEREDOC)
			tmp->f_name = hendl_doloar_comand(data, tmp->f_name);
		tmp = tmp->next;
	}
}

// $ls|"$ls   "
//  asfas >>   out
int parsing(t_data *data, char *ptr)  //return 
{
	if (check_quote_double(ptr) != 0)
		return (1);
	split_string(ptr, data); // ls|ls | "|ls|"  sxala ashxatum
	t_pipe *tmp1 = data->pipe;
	while (tmp1)
	{
		tmp1->red = redirect_test(tmp1); // sxal ls>a>b
		expand_redirect_dollar(data, tmp1->red);
		heredoc(data, tmp1->red);
		if (open_files_for_redirect(tmp1) != 0)
			return (1);
		split_s__to_argv(data, tmp1); // *(42) => 1
		tmp1 = tmp1->next;
	}
	printf_pipe(data->pipe);
	printf("pipe count: %d\n", data->pipe_count);
	return (0);
}