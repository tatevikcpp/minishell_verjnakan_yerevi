#include "minishell.h"

char	*ft_strjoin_ft(char const *s1, char c)
{
	char	*ptr;
	int		k;

	k = ft_strlen(s1);
	ptr = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1 != '\0')
		*ptr++ = *s1++;
	if (c)
		*ptr++ = c;
	*ptr = '\0';
	return (ptr - k - 1);
}

t_redirect	*redirect_test(t_pipe *pipe)
{
	int 		i;
	t_pipe 		*top;
	t_redirect	*head;

	i = 0;
	top = pipe;
	head = NULL;
	top->s = NULL;
	// top->head_env = NULL;
	while (top->content[i] != '\0')
	{
		while (top->content[i] <= 32)
			i++;
		if (is_redirect_in(top->content[i]) || is_redirect_out(top->content[i]))
			redirect_f_name_flag(top, &head, &i);
		else
		{
			redirect_to_command(top, &i); // sxal funkciayi anun
			i--;
		}
		if (top->content[i])
			i++;
	}
	return (head);
}

int	redirect_f_name_flag(t_pipe *top, t_redirect **head, int *i)
{
	int		x;
	int		start;
	char	*tmp;

	x = 1;
	if (is_redirect_in(top->content[*i]) || is_redirect_out(top->content[*i]))
	{
		if (is_append_in(top->content[*i], top->content[*i + 1]) || is_append_out(top->content[*i], top->content[*i + 1]))
			x++;
		tmp = ft_substr(top->content, *i, x);
		*i += x;
		while (is_space(top->content[*i]))
			(*i)++;
		start = *i;
		while (!ft_strchr(METACHARACTER, top->content[*i]))
			(*i)++;
		ft_t_redirect_add_back(head, new_t_redirect(ft_substr(top->content, start, *i - start), tmp));
		x = 1;
		*i -= 1;
	}
	else
		return(1);
	if (top->content[*i])
		(*i)++;
	return (0);
}

int	redirect_to_command(t_pipe *top, int *i)
{
	int k;
	char *tmp_comand;
	
	k = 0;
	if (top->content[*i] == '\'')
		redirect_to_quote(top,  i, '\'');
	else if (top->content[*i] == '"')
		redirect_to_quote(top,  i, '"');
	k = (*i);
	if (top->content[*i] == '$' && (ft_isalpha(top->content[*i + 1]) || top->content[*i + 1] == '_'))
		top->s = ft_strjoin(top->s, hendl_dolar(top, top->content, i));
	while (top->content[*i] && !ft_strchr(METACHARACTER, top->content[*i]))
		(*i)++;
	tmp_comand = ft_substr(top->content, k, *i - k + 1);
	if (tmp_comand[0] != '$')
		top->s = ft_strjoin(top->s, ft_strtrim(tmp_comand, METACHARACTER));
	top->s = ft_strjoin_ft(top->s, 42);
	if (top->content[*i])
		(*i)++;
	return (1);
}

/* char	* */ void	redirect_to_quote(t_pipe *top, int *i, char c)
{
	if (top->content && *i < ft_strlen(top->content))
	{
		if (top->content[*i] == c)
		{
			(*i)++;
			top->s = ft_strjoin(top->s, split_quote(top->content, &(*i), c));
			top->s = ft_strjoin_ft(top->s, 42);
		}
		(*i)++;
	}
	// return (top->s);
}

//--------------------sevagrutyun------------------------/

/* void	redirect_to_quote_dolar(t_pipe *top, int *i, char c)
{
	
	if (top->content && *i < ft_strlen(top->content))
	{
		if (top->content[*i] == c)
		{
			// (*i)++;
			if ((ft_isalpha(top->content[*i + 1]) || top->content[*i + 1] == '_'))
			{
				top->s = ft_strjoin(top->s, split_quote(top->content, &(*i), c));
				top->s = ft_strjoin_ft(top->s, 42);
			}
		}
		(*i)++;
	}
} */

//******************************************

void	split_s__to_argv(/* t_data *data, */ t_pipe *pipe)
{
	pipe->argv = ft_split(pipe->s, 42);
}

char *hendl_dolar(t_pipe *pipe, char *str, int *i)
{
    int k;
    char *str1;
    char *val;

	(*i)++;
	k = *i;
	while((ft_isalpha(str[*i + 1]) || str[*i + 1]  == '_' || ft_isdigit(str[*i + 1])))
		(*i)++;
	// printf("str: %s\n", str);
	str1 = ft_substr(str, k, *i - k + 1);
	val = get_dolar_val(pipe, str1);
	// printf("val: %s\n", val);
	(*i)--;
	return (val);
}

char *get_dolar_val(t_pipe *pipe, char *str1)
{
    t_env	*head;
    char	*str;

    head = pipe->head_env;
    while (head)
    {
        if (ft_strcmp(head->key , str1) == 0)
			str = head->val;
		// else
		// 	str = "";
        head = head->next;
    }
	// printf("%s\n", str);e
    return (str);
}