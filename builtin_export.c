#include "minishell.h"

void split_readline(char *ptr,t_pipe *pipe, t_data *data)
{
    char **str;
    // int i;

    printf("111 %s\n", pipe->head_env->key);
	str = ft_split(ptr, ' ');

    // i = 0;
    if (ft_strcmp("export", str[0]) == 0)
        builtin_export(pipe->head_env, ptr);
    else 
        pipe_exec(data);


}


void builtin_export(t_env *head_env, char *ptr)
{
    int i;
    char **str;
    char **str1;
    t_env *head;
    t_env *new; 

    head = head_env;

    i = 1;
    // str = ft_split(ptr, ' ');
    while (head)
    {
        printf("head->key before while: %s\n", head->key);
        if (head->next)
            head = head->next;

    }
    // while (str[1] != NULL)
    // { 
    //     str1 = ft_split(str[i], '=');
    //     int j = 0;
    //     while (head)
    //     {

    //         printf("fngkfnkght %d\n", j++);
    //     //     printf("head->key in while: %s\n", head->key);
    //     //     // if (ft_strcmp(str1[0], head->key) == 0)
    //     //     // {
    //     //     //     head->val = str1[1];
    //     //     //     printf("val: %s\n", head->val);
    //     //     // }
    //     //     // if (head->next == NULL && str1[0] != head->key)
    //     //     // {
    //     //     //    new = new_t_env(str1[0], str1[1]);
    //     //     //    ft_t_env_add_back(&head, new);
    //     //     //     break;
    //     //     // }
    //         head = head->next;
    //     }
        // i++;
    }

// }