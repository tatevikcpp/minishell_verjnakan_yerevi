#include "minishell.h"

int strcmp_env(char *str, char **argv) // env-i pahy poxel
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (argv && argv[i])
    {
        if (ft_strcmp(str, argv[i]) == 0)
            flag++;
        i++;
    }
    if (flag == i)
        return (0);
    return (1);
}

int choose_builtin(t_pipe *pipe , t_data *data)
{
    if (ft_strcmp("export", pipe->argv[0]) == 0)
        return(builtin_export(pipe), 0);
    else if (ft_strcmp("echo", pipe->argv[0]) == 0)
       return(ft_echo(pipe->argv), 0);
    else if (ft_strcmp("cd", pipe->argv[0]) == 0)
       return(ft_cd(pipe->argv , data));
    else if (ft_strcmp("exit", pipe->argv[0]) == 0)
        ft_exit(pipe->argv);
    else if (ft_strcmp("pwd", pipe->argv[0]) == 0)
       return(ft_pwd());
    else if (strcmp_env("env", pipe->argv) == 0)
       return(buildin_env_all(pipe), 0);
    else if (ft_strcmp("unset", pipe->argv[0]) == 0)
        return(ft_list_remove_if(pipe, ft_strcmp), 0);
    return (0);
}

int ther_are_equal(char *ptr)
{   
    int j;

    j=0;   
    while(ptr[j])
    {
        if(ptr[j] == '=' && ptr[j+1] == '\0')
            return (1);             
    j++;
    }
    return (0);
}

void export_plus(int *i, char **str1, t_pipe *pipe, int len)
{
    char *str=ft_strdup("");
    t_env *head;
    t_env *new; 

    str = ft_substr(str1[0], 0, len-1);
    head = pipe->head_env;
    while (head)
    {            
        if (ft_strcmp(str, head->key) == 0)
        {
            head->val = ft_strjoin(head->val, str1[1]);
            break;
        } 
        if (head->next == NULL && ther_are_equal(pipe->argv[*i])==1)
        {   
            new = new_t_env(str,"\1");
            ft_t_env_add_back(&head, new);
            break;
        }                  
        if (head->next == NULL)
        {
            new = new_t_env(str, str1[1]);
            ft_t_env_add_back(&head, new);
            break;
        }            
        head = head->next;
    } 
}

void built_in_creat(int *i, char **str1, t_pipe *pipe)
{
    t_env *head;
    t_env *new; 

    head = pipe->head_env;
    while (head)
    {            
        if (ft_strcmp(str1[0], head->key) == 0)
        {
            head->val = str1[1];
            break;
        } 
        if (head->next == NULL && ther_are_equal(pipe->argv[*i])==1)
        {   
            new = new_t_env(str1[0],"\1");
            ft_t_env_add_back(&head, new);
            break;
        }                  
        if (head->next == NULL)
        {
            new = new_t_env(str1[0], str1[1]);
            ft_t_env_add_back(&head, new);
            break;
        }            
        head = head->next;
    } 

}

void builtin_export(t_pipe *pipe)
{  
    int i;
    char **str1;
    // char *str=ft_strdup("");
    
    i = 1;
    if (!pipe->argv[1])
    {
        buildin_export_all_by_alphabet(pipe);
        buildin_export_all(pipe);
    }
    while (pipe->argv[i])
    { 
        str1 = ft_split(pipe->argv[i], '=');
        int len = ft_strlen(str1[0]);
        if ( str1[0][len-1] == '+' )
            export_plus(&i, str1, pipe, len);
        else if (ft_strcmp(hendl_export_var(str1[0]), "not a valid identifier") == 0)
            printf("minishell:  %s `%s' not a valid identifier\n", pipe->argv[0], pipe->argv[i]);
        else
            built_in_creat(&i, str1, pipe);
        i++;
    }
}


char *hendl_export_var(char *str1)
{
    int k;

    k = 0;
    if (ft_isalpha(str1[k]) == 0 && str1[k] !=  '_')
    {
        return ("not a valid identifier");
    }
    k++;
    while (str1[k])
    {
        if (ft_isalpha(str1[k]) == 0 && str1[k] !=  '_'  && ft_isdigit(str1[k]) == 0 )
            return ("not a valid identifier");
        k++;
    }
    return (str1);
}

void buildin_export_all(t_pipe *pipe)
{
	t_env *head;
    
    head = pipe->head_env;
    while (head)
    {
        if (head->val == NULL)
            printf("declare -x %s\n", head->key);
        else  
            printf("declare -x %s=\"%s\"\n", head->key, head->val);
        if(head->next == NULL)
            return;
        head = head->next;
    }
}

void buildin_export_all_by_alphabet(t_pipe *pipe)
{
    t_env *head;
    int count;
    int i;
    count = 0;
    i = 0;    
    head = pipe->head_env;
    while (head)
    {        
        count++;
        head = head->next;
    }    
    while (i < count)
    {      
        buildin_export_all_by_alphabet_inner(pipe); 
        i++;
    }
}

void buildin_export_all_by_alphabet_inner(t_pipe *pipe) 
{
    t_env   *head;
    char    *tmp;
    char    *tmp_val;
   
    head = pipe->head_env;   
    while (head->next)
    {
        if (head->key[0] > head->next->key[0])
        {
            tmp_val = head->val;
            tmp = head->key;
            head->val = head->next->val;
            head->key = head->next->key;
            head->next->val = tmp_val;
            head->next->key = tmp;                
        }            
        head = head->next;
    }
}

void buildin_env_all(t_pipe *pipe)
{
	t_env *head;
   
    head = pipe->head_env;
	while (head)
	{
        if (head->key && head->val)
		    printf("%s=%s\n", head->key, head->val);
        if(head->next == NULL)
			return;
		head = head->next;
	}
}

int ft_list_remove_if(t_pipe *pipe, int (*ft_strcmp)())
{    
    char **str1;
    int i;
     
    i = 1;   
    while (pipe->argv[i])
    {
        str1 = ft_split(pipe->argv[i], '=');
        if (ft_strcmp(hendl_export_var(str1[0]), "not a valid identifier") == 0)
            printf("minishell:  %s `%s' not a valid identifier\n", pipe->argv[0], pipe->argv[i]);
        remove_else_inner(pipe, ft_strcmp, str1);       
        i++;
    }
    return (0);
}

void remove_else_inner(t_pipe *pipe, int (*ft_strcmp)(), char **str1)
{
    t_env   *head;
    t_env   *new;
    t_env   *tmp;

    head = pipe->head_env;
    if (head == NULL)
        return ;
    if (head && ft_strcmp(head->key, str1[0])==0)
    {
        new = head;
        head= head->next;
        free(new);
    }
    new = head;
    while (new && new->next)
    {
        if (ft_strcmp(new->next->key,str1[0]) == 0)
        {
            tmp = new->next;
            new->next = tmp->next;
                free(tmp);	
        }
        new = new->next;
    }
}