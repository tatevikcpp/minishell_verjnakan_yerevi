#include "minishell.h"

void heredoc(char *ptr,t_data *data)
{
    char *s;
    int fd[2];
    ptr+=2;
    pipe(fd);
    while (1)
    {
        s = readline("herdoc:");
        // printf("s,,,%s\n",s);
        //  printf("ptr%s\n",ptr);
        if (ft_strcmp(s,ptr) == 0)
            break;
        write(fd[1], s, ft_strlen(s));
        write(fd[1], "\n", 1);
        free(s);
        // s = NULL;
    }
    close(fd[1]);
    data->fd_herdoc = fd[0];
}

void append_red()
{
  /*   if (ft_strcmp("ls") == 0) */
//   printf("A\n");
            // open("file.txt", O_CREAT | O_RDWR | O_APPEND, 0644); 
    // printf("B\n");
        
       
    
}

void choose_redirect(t_data *data, char *ptr)
{
    char *lol=malloc(sizeof(char)*3);
    int i=0;
    while(ptr[i])
    {
        if(ptr[i] == '>' && ptr[i+1] == '>')
            lol=ft_substr(ptr, i, 2);
        break;
    }
    t_redirect redirection;
    data->pipe->red = &redirection;
    
    while (data->pipe->red)
    {
    if (ft_strcmp(/* data->pipe->red->flag, */ lol, ">>") == 0)
        append_red(/* data */);
       data->pipe->red=data->pipe->red->next;
    }

}

// char *heredoc(char *ptr, t_data *data)
// {
//     char *s;
//     // int fd;
//     char *file;

//     char *result;

//     file = ft_strjoin(".hd", ptr);
//     ptr += 2;
//     file = ptr;
//    data->fd_herdoc = open(file, O_CREAT | O_RDWR | O_TRUNC,0644);
//     if(data->fd_herdoc==-1){
//         printf("error");
//     return("errorE");
//     }
//         printf("fd_herdoc %d\n", data->fd_herdoc);
//     while (1)
//     {
//         s = readline("herdoc:");
//         // printf("s,,, %s\n",s);
//         //  printf("ptr %s\n",ptr);
//         if (ft_strcmp(s,ptr) == 0)
//             break;
//         write(data->fd_herdoc, s, ft_strlen(s));
//         write(data->fd_herdoc, "\n", 1);
//         free(s);
        
//         s = NULL;
//         //   printf("fd2 %d\n", fd_herdoc);
//     }
//         // if (dup2(fd_herdoc, 1) < 0)
//         //     printf("ASFDGHASFHDAS\n");
//         // printf("dup2\n");
//         close(data->fd_herdoc);
//         data->fd_herdoc = open(file, O_RDONLY);
 
//     // dup2(fd_herdoc, 0);
//     return (result);
// }