#include "minishell.h"

// >>        a>>b>>c<d<e>f<<g<<h ls -la
// ">>        a>>b>>c<t<o>p<<t<<u ls -la";  ays depq@ chi ashxatum
// echo  >> amalia | ls <t >u -la | he'l'lo >> | m 'hello  | world'  

// 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
/* char *fun(char *top, int *i)
{
	// int count = 0;
	int first = 0;
	// int second = 0;
	char * str = malloc(sizeof(char));

	first = *i;
	// count++;
	while (top[*i] != '"')
	// printf("while i: %d\n", i);
		(*i)++;
	// second = i;
	printf("first %i\n ",first);
	// printf("second %i\n ",second);
	str =  ft_substr(top, first, *i - first);
	printf("str: %s\n ", str);
	// str = ft_strjoin(str, "\"");
	
			
return (str);
}

t_redirect	*redirect_test(t_pipe *pipe)
{
	int i;
	t_pipe *top = pipe;
	t_redirect	*head = NULL;

	i = 0;
	// pipe->argv = calloc(100, 8);
	while (top->content[i] != '\0')
	{
		// while (!ft_strchr(METACHARACTER, top->content[i]))
		// 	i++;
		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
		{
			// printf("red_iiii = %d\n", i);
			redirect_f_name_flag(top, &head, &i);
			// printf(" i = %d\n", i);
		}
		else if (top->content[i] > 32)
		{
			printf("iii_else = %d\n", i);
			redirect_to_command(top,  &i); //ok_offf
			// printf(" i_else = %d\n", i);
		}
	i++;
	}
	print_list(head);
	return (head);
}
void	redirect_to_command(t_pipe *top, int *i)
{
	int k;
	int l;
	// int first;
	char *tmp1 = ft_strdup("");
	char *tmp;
	// t_pipe	*head = NULL;
	// int len;
	char *arr;
	t_redirect	*head = NULL;
	
	k= 0;
	l = 0;
	// top->argv = calloc(100, 8);	
	if (*i < ft_strlen(top->content))
	{
		if (top->content[*i] == '\"')
		{
			(*i)++;
			printf("in havasatr e = %d\n", *i);
			arr = fun(top->content, &(*i));
			top->argv = &arr;
			printf("arr = %s\n", arr);
			// printf("top->argv[%d] = %s\n",l-1, top->argv[l-1]);
			printf("top->argv[%d] = %s\n", l, top->argv[l]);
		}
		else
		{
			// k = (*i)++;
			k = (*i);
			printf("i_k=== %d\n", *i);
			while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i])) //redirecty petq chi
			{
				printf("bayc\n");
				(*i)++;
			}
			if ((is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i])) || 
				is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i]))
			{
				printf("offf\n");
				redirect_f_name_flag(top, &head, i);// comment "stex"
			}
			// printf("***i = %d\n", *i);
			tmp = ft_substr(top->content, k, *i - k);
			// printf("tmp = %s\n", tmp);
			tmp1 = ft_strjoin(tmp1,tmp);
			tmp1 = ft_strjoin(tmp, "*");
			printf("tmp1 = %s\n", tmp1);		
			// printf("top->argv[%d ] = %s\n",l-1, top->argv[l - 1]);
		}
	}
}

void	redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i) 
{
	int x;
	int start;
	char	*tmp;

	// printf("out?\n");
	x = 1;
	start = 0;
	// printf("i_ners = %d\n", *i);
	// if ( *i > 0)
	// 	*i -= 1;
	if (is_append_in(top->content[*i], top->content[*i + 1]) || is_append_out(top->content[*i], top->content[*i + 1]))
	{
		x++;
		printf("stex\n");
	}
	tmp = ft_substr(top->content, *i, x);
	*i += x;
	while (is_space(top->content[*i]))
		(*i)++;
	start = *i;
	// printf("start = %d\n", start);
	while (!ft_strchr(METACHARACTER, top->content[*i]))
		(*i)++;
	ft_t_redirect_add_back(head, new_t_redirect(ft_substr(top->content, start, *i - start), tmp));			
	x = 1;
	// *i -= 1;
} */

//0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000




//  t_redirect	*redirect_test(t_pipe *pipe) 
// {
// 	int i;
// 	int	x;
// 	// int	k;
// 	int	start;
// 	// int	first;
// 	char	*tmp;

// 	x = 1;
// 	i = 0;
// 	t_pipe *top = pipe;
// 	t_redirect	*head = NULL;
// 	pipe->argv = calloc(50, 8);
	
// 	// int l = 0;
// 	while (top->content[i] != '\0')
// 	{

// 		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
// 		{
// 			if (is_append_in(top->content[i], top->content[i + 1]) || is_append_out(top->content[i], top->content[i + 1]))
// 				x++;
// 			tmp = ft_substr(top->content, i, x);
// 			// ptr->flag = ft_substr(top->content, i, x);
// 			i += x;
// 			while (is_space(top->content[i]))
// 				i++;
// 			start = i;
// 			while (!ft_strchr(METACHARACTER, top->content[i]))
// 				i++;
// 			ft_t_redirect_add_back(&head, new_t_redirect(ft_substr(top->content, start, i - start), tmp));
// 			// ptr->f_name = ft_substr(top->content, start, i - start);
// 			// ptr->next = malloc(sizeof(t_redirect));
// 			// ptr = ptr->next;
// 			x = 1;
// 			i -= 1;
// 		}
// 		// else 
// 		// {
// 		// 	// if (i < ft_strlen(top->content))
// 		// 	// {
// 		// 	// 	if (/* top->content[i] == '\'' || */ top->content[i] == '\"')
// 		// 	// 	{
// 		// 	// 		first = i;					
// 		// 	// 		str1 = fun(top->content, i);
// 		// 	// 		printf("ooool\n");
// 		// 	// 		// int  for_space(char *ptr, char c, int i); 
// 		// 	// 	} 
// 		// 	// 	else
// 		// 	// 	{
// 		// 			while (is_space(top->content[i]))
// 		// 				i++;
// 		// 			k = i++;
// 		// 			// printf("k=%d\n", k);
// 		// 			while (top->content[i] && !ft_strchr(METACHARACTER, top->content[i])) /* && (top->content[i] != '\'' || top->content[i] != '"') */
// 		// 				i++;
// 		// 			pipe->argv[l++] = ft_substr(top->content, k, i - k);
// 		// 			printf("pipe->argv[l - 1] = %s\n", pipe->argv[l - 1]);
// 		// 			// str = ft_strjoin(str, ft_substr(top->content, k, i - k));
					
// 		// 			// str = ft_strjoin(str, " ");
// 		// 	// 	}
// 		// 	// }
// 		// }
// 		if (top->content[i])
// 			i++;
// 	}
//***********************************************************************************************
	// if (str1 != NULL)
	// {
	// 	// printf("str1%s\n", str1);
	// 	pipe->argv = ft_split(str1, '\"');	
	// }
	// else
	// 	pipe->argv = ft_split(str, ' ');
	// while (pipe->argv[l])
	// {
	// 	printf("argv[%d] %s\n",l, pipe->argv[l]);
	// 	l++;
	// }
// 	 print_list(head);
// 	return (head);
// } 
//000000000000000000000000000000000000000000000000000000000
// /* t_redirect	*redirect(t_pipe *pipe) 
// {
// 	t_redirect	*ptr;
// 	t_redirect	*head;
// 	t_pipe *top;
	
// 	char *str = (char *)malloc(sizeof(char));
// 	int i = 0;
// 	int	x;
// 	int start;
// 	int end = 0;
// 	int k;
// 	char *name;
// 	ptr = malloc(sizeof(t_redirect));
// 	char	*str1 = NULL;
// 	head = ptr;
// 	x = 1;
// 	k = 0;
// 	int count = 0;
// 	int first = 0;
// 	int second = 0;
// 	char **arr;

// 	top = pipe;	
// 	// t_redirect noder@ mek hat avel e
// 	while (top)
// 	{
// 		while (top->content[i] != '\0')
// 		{

// 			if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
// 			{
// 				if (is_append_in(top->content[i], top->content[i + 1]) || is_append_out(top->content[i], top->content[i + 1]))
// 					x++;
// 				ptr->flag = ft_substr(top->content, i, x);
// 				i += x;
// 				while (is_space(top->content[i]))
// 					i++;
// 				start = i;
// 				while (!ft_strchr(METACHARACTER, top->content[i]))
// 					i++;
// 				ptr->f_name = ft_substr(top->content, start, i - start);
// 				ptr->next = malloc(sizeof(t_redirect));
// 				ptr = ptr->next;
// 				x = 1;
// 				i -= 1;
// 			}
// 			else 
// 			{
// 				if (i < ft_strlen(top->content))
// 				{
// 					if (/* top->content[i] == '\'' || */ top->content[i] == '\"')
// 					{
// 						first = i;					
// 						str1 = fun(top->content, i);
// 						printf("ooool\n");
// 						// int  for_space(char *ptr, char c, int i); 
						
// 					} 
// 					else
// 					{
// 						while (is_space(top->content[i]))
// 							i++;
// 						k = i;
// 						printf("k=%d\n", k);
// 						while (top->content[i] && ft_isprint(top->content[i]) /* && (top->content[i] != '\'' || top->content[i] != '"') */)
// 							i++;
// 						str = ft_strjoin(str, ft_substr(top->content, k, i - k));
// 						str = ft_strjoin(str, " ");
// 					}
					
// 				}
// 			}
// 			i++;
// 		}
		
// 		top = top->next;
// 	}
// 	printf("frt%d\n", first);
// 	printf("jh= %s\n", str);
// 	print_list(head);
// 	if (str1 != NULL)
// 	{
// 		// printf("str1%s\n", str1);
// 		pipe->argv = ft_split(str1, '\"');	
// 	}
// 	else
// 		pipe->argv = ft_split(str, ' ');
// 	int l = 0;
// 	while (pipe->argv[l])
// 	{
// 		printf("argv[%d] %s\n",l, pipe->argv[l]);
// 		l++;
// 	}
// 	return (head);
// } */

void print_list(t_redirect *red)
{
	t_redirect *head;

	head = red;
	while (head)
	{
		// printf("flag: %s \n ", head->flag);
		printf("f_name: %s\n", head->f_name);
		// printf("type: %s\n", head->type); // miangaminic grel "char **argv" i mech
		head = head->next;
	}

	head = red;

	while (head)
	{
		printf("flag: %s\n", head->flag);
		// printf("f_name: %s \n ", head->f_name);
		// printf("type: %s\n", head->type); // miangaminic grel "char **argv" i mech
		head = head->next;
	}
}

void print_list_head_env(t_data data)
{
	t_env *head;

	head = data.head_env;
	while (head)
	{
		// printf("HEEELOO\n");
		printf("head->key: %s\n, head->val: %s\n, ", head->key, head->val);
		// printf("f_name: %s, ", head->val);
		// printf("type: %s\n", head->type); // miangaminic grel "char **argv" i mech
		head = head->next;
	}
}

void send_env(t_data *data)
{
	t_env	*head;
	char	*str;
	char	*str1 = ft_strdup(" ");

	head = data->head_env;
	while (head->next)
	{
		str = ft_strjoin(head->key,"=");
		str = ft_strjoin(str,head->val);
		str = ft_strjoin(str," ");
		// data.env = &str;
		str1 = ft_strjoin(str1,str);
		head = head->next;
	}
printf("str1=%s\n", str1);
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
