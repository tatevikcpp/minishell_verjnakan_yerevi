#include "minishell.h"

void split_readline(char *ptr , t_pipe *pipe, t_data *data)
// void split_readline(char *ptr ,/*t_pipe *pipe, */ t_data *data)
{
    // char **str;
  
	// str = ft_split(ptr, ' ');
    if (ft_strcmp("echo", pipe->argv[0]) == 0)
        ft_echo(pipe->argv);
    // if (ft_strcmp("cd", str[0]) == 0)
    //     ft_cd(str[1], data);
    // if (ft_strcmp("exit", str[0]) == 0)
    //     ft_exit(str, data);
    // if (ft_strcmp("pwd", str[0]) == 0)
    //     ft_pwd();
            
    // if (ft_strcmp("env", str[0]) == 0 && !str[1])  
    //     buildin_env_all(data);
    // if (ft_strcmp("export", str[0]) == 0 && !str[1])
    //    {
    //     buildin_export_all_by_alphabet(data);
    //     buildin_export_all(data/* , ptr */);
    //    }   
    // if (ft_strcmp("export", str[0]) == 0)
    //     builtin_export(data, ptr);
    // if (ft_strcmp("unset", str[0]) == 0)
    //     ft_list_remove_if(data,ft_strcmp, ptr);
        // unset_buildin(data, ptr);
    /* else 
        pipe_exec(data); */


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

void builtin_export(t_data *data, char *ptr)
{  
    int i;
    char **str;
    char **str1;
    t_env *head;
    t_env *new; 

    i = 1;
    str = ft_split(ptr, ' ');
    while (str[i])
    { 
        ther_are_equal(str[i]);        
        str1 = ft_split(str[i], '=');
       
        head = data->head_env;
        if (ft_strcmp(hendl_export_var(str1[0]), "not a valid identifier") == 0)
        {
            printf("not a valid identifier\n");
            return ;
        }  
        while (head)
        {            
            if (ft_strcmp(str1[0], head->key) == 0)
            {
                head->val = str1[1];
                break;
            } 
            if (head->next == NULL && ther_are_equal(str[i])==1)
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
        i++;
    }

}

char *hendl_export_var(char *str1)
{
    int k;

    k = 0;
    if (ft_isalpha(str1[k]) == 0 && str1[k] !=  '_')
    {
        printf("str1 %s\n",str1);
        return ("not a valid identifier");
    }
    k++;
    while (str1[k])
    {
        printf("str1[%d] %s\n",k, &str1[k]);
        if (ft_isalpha(str1[k]) == 0 || str1[k] !=  '_' ||  ft_isdigit(str1[k]) == 0)
            return ("not a valid identifier");
        k++;
    }
    return (str1);
}

void buildin_export_all(t_data *data/* , char *ptr */)
{
	t_env *head;
    
    head = data->head_env;
    while (head)
    {
        if (head->val == NULL)
            printf("declare -x %s \n", head->key);
        else  
            printf("declare -x %s =\"%s\"\n", head->key, head->val);
        if(head->next == NULL)
            return;
        head = head->next;
    }
}

void buildin_export_all_by_alphabet(t_data *data)
{
    t_env *head;
    int count;
    int i;
   
    count=0;
    i=0;    
    head = data->head_env;
    while (head)
    {        
        count++;
        head = head->next;
    }    
    while (i < count)
    {      
        buildin_export_all_by_alphabet_inner(data); 
        i++;
    }
}

void buildin_export_all_by_alphabet_inner(t_data *data)
{
    t_env *head1;
    char *tmp;
    char *tmp_val;
   
    head1 = data->head_env;   
    while (head1->next)
    {
        if (head1->key[0]>head1->next->key[0])
        {
            tmp_val=head1->val;
            tmp = head1->key;
            head1->val = head1->next->val;
            head1->key = head1->next->key;
            head1->next->val = tmp_val;
            head1->next->key = tmp;                
        }            
        head1 = head1->next;
    }
}

void buildin_env_all(t_data *data/* , char *ptr */)
{
	t_env *head;
   
	head = data->head_env;
	while (head)
	{
        if (head->key && head->val)
		    printf("%s=%s\n", head->key, head->val);
        if(head->next == NULL)
			return;
		head = head->next;
	}
}

// void unset_buildin(t_data *data, char *ptr)
// {
//     t_env *head;
//     t_env *tmp;
//     char **str;
//     char **str1;
//     int i;

//     i = 1;
//     str = ft_split(ptr,' ');
//     while (str[i])
//     {
//         str1 = ft_split(str[i], '=');
//         head = data->head_env;
//         while (head)
//         {
//             // ft_list_remove_if(lst,a,strcmp);
//             if (ft_strcmp(str1[0], head->next->key) == 0)
//             {
//                 tmp= head->next;
//                 head=head->next->next;
//                 free(tmp);
//                 break;
//             } 
            
//             if(head->next == NULL)
//                 return;
//             head = head->next;
//         }
//         i++;
//     }
// }
void ft_get_remove_val(t_data *data,int (*ft_strcmp)(), char *str)
{
    t_env	*head;
    char *line1;
    char *line;
    int len;

    len = ft_strlen(str);
    line = malloc(sizeof(char) * (len + 1));
    line = ft_substr(str,1,len-1);
    head = data->head_env;
    while (head)
    {               
        if (ft_strcmp(line, head->key) == 0)
        {
            line1= head->val;                   
            break;
        }                
        head = head->next;
    } 
             
    remove_if_inner(data, ft_strcmp, line1); 
}

void ft_list_remove_if(t_data *data,int (*ft_strcmp)(), char *ptr)
{
    
    char **str;
    char **str1;
    int i;
     
    i = 1;
    str = ft_split(ptr,' ');
    while (str[i])
    {
        str1 = ft_split(str[i], '=');
        if (str1[0][0]=='$')
        {
            ft_get_remove_val(data,ft_strcmp,str1[0]);            
        }
        else
            remove_else_inner(data, ft_strcmp, str1);       
        i++;
    }
}

void remove_else_inner(t_data *data,int (*ft_strcmp)(), char **str1)
{
    t_env	*head;
    head = data->head_env;
    if (head==NULL)
        return ;
    t_env	*new;
    t_env	*tmp;
    if (head && ft_strcmp(head->key, str1[0])==0)
    {
        new = head;
        head= head->next;
        free(new);
    }
    new = head;
    while (new && new->next)
    {
        if (ft_strcmp(new->next->key,str1[0])==0)
        {
            tmp = new->next;
            new->next = tmp->next;
                free(tmp);	
        }
        new = new->next;
    }
}

void remove_if_inner(t_data *data,int (*ft_strcmp)(), char *str)
{
    t_env	*head;
    head = data->head_env;
    if (head==NULL)
        return ;
    t_env	*new;
    t_env	*tmp;
    if (head && ft_strcmp(head->key, str)==0)
    {
        new = head;
        head= head->next;
        free(new);
    }
    new = head;
    while (new && new->next)
    {
        if (ft_strcmp(new->next->key, str)==0)
        {
            tmp = new->next;
            new->next = tmp->next;
                free(tmp);	
        }
        new = new->next;
    }
}


   



