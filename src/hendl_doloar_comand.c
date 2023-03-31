/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendl_doloar_comand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:27:47 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/31 20:31:30 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_handle_dollar
{
	int		i;
	int		j;
	int		is_in_single;
	int		is_in_double;
	char	*ptr;
	char	*str1;
	char	*str_line;
}	t_handle_dollar;

static void adjust_stat(char c, int *is_in_single, int *is_in_double)
{
    if (c == '\'' && !*is_in_double)
    {
        if (*is_in_single == 1)
            *is_in_single = 0;
        else
            *is_in_single = 1;
    }
    if (c == '"' && !*is_in_single)
    {
        if (*is_in_double == 1)
            *is_in_double = 0;
        else
            *is_in_double = 1; // = 1
    }
}

static void	init_t_handle_dollar(t_handle_dollar *dollar)
{
    dollar->i = 0;
    dollar->j = 0;
    dollar->is_in_single = 0;
    dollar->is_in_double = 0;
    dollar->str_line = NULL;
    dollar->ptr = NULL;
}

static void hendl_doloar_comand_helper(t_data *data, char *test,\
t_handle_dollar *dollar)
{
    dollar->j++;
    dollar->i = dollar->j;
    while((ft_isalpha(test[dollar->j]) || test[dollar->j] == '_'
        || ft_isdigit(test[dollar->j]) || test[dollar->j] == '?'))
        dollar->j++;
    dollar->str1 = ft_substr(test, dollar->i,dollar->j - dollar->i);
    dollar->ptr = get_dolar_val(data, dollar->str1);
    free(dollar->str1);
    if (dollar->ptr)
        dollar->str_line = ft_strjon_free_arg1(dollar->str_line,dollar->ptr);
    dollar->j--;
}

char    *hendl_doloar_comand(t_data *data, char *test)
{
    t_handle_dollar dollar;

    init_t_handle_dollar(&dollar);
    while(test[dollar.j])
    {
        adjust_stat(test[dollar.j], &dollar.is_in_single, &dollar.is_in_double);
        while (test[dollar.j] && ((test[dollar.j] == '"'
            && !dollar.is_in_single)
            || (test[dollar.j] == '\'' && !dollar.is_in_double)))
            dollar.j++;
        if (!dollar.is_in_single && test[dollar.j] == '$'
            && (ft_isalpha(test[dollar.j+1]) || test[dollar.j + 1] == '_'
            || test[dollar.j + 1] == '?'))
            hendl_doloar_comand_helper(data, test, &dollar);
        else if (!(test[dollar.j] == '\'' && dollar.is_in_single)
            && !(test[dollar.j] == '"' && dollar.is_in_double))
        {
            dollar.ptr = ft_substr(test, dollar.j, 1);
            dollar.str_line = ft_strjon_free_both(dollar.str_line, dollar.ptr);
        }
        if (test[dollar.j] && !(test[dollar.j] == '\'' && dollar.is_in_single)
            && !(test[dollar.j] == '"' && dollar.is_in_double))
            dollar.j++;
	}
    return (dollar.str_line);
}
