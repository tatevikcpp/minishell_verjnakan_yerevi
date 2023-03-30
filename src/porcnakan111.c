#include "minishell.h"
// $A
void hendl_dolar(t_data *data, char *str)
{
    int     i;
    int     j;    
    char    *str1;
    char    *val;

    i = 0;
    j = 0;
    while (str[j])
    {
        if (str[j] == '$' && (ft_isalpha(str[j+1]) || str[j+1] == '_'))
        {
            j++;
            i = j;
            while((ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
                j++;
            str1 = ft_substr(str,i,j - i);
            data->len_key_sum += ft_strlen(str1);
            val = get_dolar_val(data, str1);
            free(str1);
            j--;
        }
        j++;
    }
}

char *get_dolar_val(t_data *data, char *str1)
{
    t_env   *head;
    
    head = data->head_env;
    while (head)    
    {
        if (ft_strcmp(head->key , str1) == 0)
            return (head->val);
        head = head->next;
    }
    return (NULL);
}

void func(char *test, int j)
{
    char    *ptr;
    char    *str_line;
    // char    *str1;

    ptr = NULL;
    str_line = ptr;

    ptr = ft_substr(test, j, 1);
    str_line = ft_strjoin(str_line,ptr);
}

// echo 'as$PW"D' "$PWD gvy'''''vgb"

char *hendl_doloar_comand(t_data *data, char *test)
{
    int     i;
    int     j;
    int     is_in_single;;
    int     is_in_double;;;
    char    *ptr = NULL;
    char    *str1;
    char    *str_line;

    i = 0;
    j = 0;
    is_in_single = 0;
    is_in_double = 0;
    str_line = NULL;
    while(test[j])
    {
        if (test[j] == '\'' && !is_in_double)
        {
            if (is_in_single == 1)
                is_in_single = 0;
            else
                is_in_single = 1;
        }
        if (test[j] == '"' && !is_in_single)
        {
            if (is_in_double == 1)
                is_in_double = 0;
            else
                is_in_double = 1; // = 1
        }
        if ((test[j] == '"' && !is_in_single) || (test[j] == '\'' && !is_in_double))
            j++;
        if (!is_in_single && test[j] == '$' && (ft_isalpha(test[j+1]) || test[j + 1] == '_' || test[j + 1] == '?'))
        {
            j++;
            i = j;
            while((ft_isalpha(test[j]) || test[j] == '_' || ft_isdigit(test[j]) || test[j] == '?'))
                j++;
            str1 = ft_substr(test,i,j - i);
            ptr = get_dolar_val(data, str1);
            free(str1);
			if (ptr)
                str_line = ft_strjon_free_arg1(str_line,ptr);
            j--;
        }
        else if (!(test[j] == '\'' && is_in_single) && !(test[j] == '"' && is_in_double))
        {
            ptr = ft_substr(test, j, 1);
            str_line = ft_strjon_free_both(str_line, ptr);
        }
        if (test[j] && !(test[j] == '\'' && is_in_single) && !(test[j] == '"' && is_in_double))// else?
            j++;
	}
    // if (is_in_single || is_in_double)
    // {
    //     ft_printf(2, "minishell: syntax error near unexpected token `%c'\n", '"');// '\'', UXXEL, huysy dnel kisvelu vtra
    //     return ((char *)0);
    // }
    return (str_line);
}

char *function(t_data *data, char *test)
{
    return (hendl_doloar_comand(data, test));
}


//leaks     'dsgsdgsd$PWD g'
