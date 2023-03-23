#include "minishell.h"

void split_string(char *input, t_data *data)
{
	int		i;
	t_pipe	*head;
	t_pipe	*node;
	int		len;
	int p;

	i = 0;
	len = ft_strlen(input);
	head = ft_lstnew(&input[0], data->head_env);
	p = i;
	while (i < len)
	{
		if(input[i + 1] == '"' && (input[i] && input[i] != '\\'))
		{
			p = for_space(input, '"', i);	
			i=p;
		}
		if(input[i + 1] == '\'' && (input[i] && input[i] != '\\'))
		
		{
			p = for_space(input, '\'', i);
			i=p;
		}
		if (input[i] == '|')
		{
			input[i] = '\0';
			node = ft_lstnew(&input[i + 1], data->head_env);
			ft_lstadd_back(&head, node);
		}
		i++;
	}
	data->pipe = head;	
}


void print_lists(t_pipe *red)
{
	t_pipe *head;

	head = red;
	while (head)
	{
		//printf("content: %s\n", head->content);
		head = head->next;
	}
}
