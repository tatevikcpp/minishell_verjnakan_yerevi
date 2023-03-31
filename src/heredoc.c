/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:15 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 20:57:47 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void heredoc_child(t_data *data, t_redirect *red, int fd)
{
    char       *s;
    char       *tmp_free;

    while (1)
    {
        s = readline("heredoc>");
        if (s == NULL || ft_strcmp(s, red->f_name) == 0)
        {
            free(s);
            s = NULL;                    
            break ;
        }
        tmp_free = s;
        s = hendl_doloar_comand(data, s);
        free(tmp_free);
        write(fd, s, ft_strlen(s));
        write(fd, "\n", 1);
    }
    close(fd);
    exit (0);
}

void heredoc(t_data *data, t_redirect *red)
{
    int         pid;
    int        fd[2];

    while (red)
    {
        if (red->flag == HEREDOC)
        {
            if (pipe(fd) == -1)
                exit(1);
            pid = fork();
            if (pid == 0)
            {
                heredoc_child(data, red, fd[1]);
            }
            red->heredoc_fd = fd[0];
            close(fd[1]);
            waitpid(pid, 0, 0);
        }
        red = red->next;
    }
}