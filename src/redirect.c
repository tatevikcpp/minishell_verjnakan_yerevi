#include "minishell.h"

// >>        a>>b>>c<d<e>f<<g<<h ls -la
// ">>        a>>b>>c<t<o>p<<t<<u ls -la";  ays depq@ chi ashxatum
// echo  >> amalia | ls <t >u -la | he'l'lo >> | m 'hello  | world'  
// echo abc &x     >>    amalia   < 121 | ls    <   t   >    u   -la | he'l'lo   >> | m 'hello  | w'
// 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

char *split_quote(char *top, int *i, char c)
{
	int	first;

	first = *i;
	char * str = malloc(sizeof(char));
	while (top[*i] != c)
		(*i)++;
	str =  ft_substr(top, first, *i - first);		
	return (str);
}

void print_list(t_redirect *red)
{
	t_redirect *head;

	printf("redirections ***********************************\n");
	head = red;
	while (head)
	{
		printf("f_name: [%s]", head->f_name);
		printf("  Mode = ");
		if (head->flag == HEREDOC)
			printf("HEREDOC\n");
		if (head->flag == O_APPEND)
			printf("O_APPEND\n");
		if (head->flag == O_RDONLY)
			printf("O_RDONLY\n");
		if (head->flag == O_TRUNC)
			printf("O_TRUNC\n");
		
		head = head->next;
	}
	printf("redirections ***********************************\n");
}

void print_list_head_env(t_data *data)
{
	t_env *head;

	head = data->head_env;
	while (head)
	{
		printf("head->key: %s\nhead->val: %s\n", head->key, head->val);
		if (head->next == NULL)
			return ;
		head = head->next;
	}
}

void send_env(t_data *data)
{
	t_env *head;
	char *str;
	char *str1 = ft_strdup(" ");

	head = data->head_env;
	while (head)
	{
		str = ft_strjoin(head->key, "=");
		str = ft_strjoin(str, head->val);
		str = ft_strjoin(str, " ");
		str1 = ft_strjoin(str1,str);
		head = head->next;
	}
	// printf("str1 = %s\n", str1);
	data->env = ft_split(str1, ' ');
}

void print_env(t_data *data)
{
	int i = 0;
	while (data->env[i])
	{
		printf("data.env = %s\n", data->env[i]);
		i++;
	}	

}


// void print_list_head_env_pipe(t_pipe *pipe)
// {
// 	printf("ok\n");
// 	t_env *head;

// 	head = pipe->head_env;
// 	while (head)
// 	{
// 		printf("head->key: %s\nhead->val: %s\n", head->key, head->val);
// 		if (head->next == NULL)
// 			return ;
// 		head = head->next;
// 	}
// }