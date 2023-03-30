#include "minishell.h"

void heredoc(t_redirect *red /*, t_pipe *p  ,  t_data *data */)
{
    int         pid;
    t_redirect *tmp;
    char       *s;
    int        fd[2];

    tmp = red;
    while (tmp)
    {
        if (tmp->flag == HEREDOC) // tmp->flag == HEREDOC
        {
            if (pipe(fd) == -1)
                exit(1);
            pid = fork();
            if (pid == 0)
            {
                while (1)
                {
                    s = readline("heredoc>");
                    if (s == NULL || ft_strcmp(s, tmp->f_name) == 0)
                    {
                        free(s);
                        s = NULL;                    
                        break;
                    }
                    write(fd[1], s, ft_strlen(s));
                    write(fd[1], "\n", 1);
                }
                close(fd[1]);
                exit (0);
            }
            tmp->heredoc_fd = fd[0];
            close(fd[1]);
            waitpid(pid, 0, 0);
        }
        tmp = tmp->next;
    }
}