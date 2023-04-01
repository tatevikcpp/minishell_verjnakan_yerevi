/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:09:30 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/04/01 21:11:25 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char *str, int *num_metka)
{
	int	i;
	int	num_digit;
	int	is_minus;

	i = 0;
	is_minus = 0;
	num_digit = 0;
	if (str[i] == '+' || (str[i] == '-' && ++is_minus))
		++i;
	if (is_digit(str + i) != 0)
		return (1);
	while (str[i] == '0')
		++i;
	num_digit = i;
	while (str[i])
		++i;
	if ((i - num_digit) > 19)
		return (1);
	if ((i - num_digit) == 19)
		if ((is_minus && ft_strcmp(str + num_digit, "9223372036854775808") > 0)
			|| (!is_minus && ft_strcmp(str + num_digit,
					"9223372036854775807") > 0))
			return (1);
	*num_metka = num_digit;
	return (0);
}

int	ft_exit(char **str, t_data *data)
{
	int		num_metka;
	char	*tmp_for_free;

	if (!str[1] && ft_printf(2, "exit\n"))
		exit(ft_atoi(get_dolar_val(data, "?")));
	tmp_for_free = str[1];
	str[1] = ft_strtrim(str[1], " \n\t");
	free(tmp_for_free);
	if (is_valid(str[1], &num_metka) != 0)
	{
		ft_printf(2, "exit\nminisehll: exit: %s: numeric argument\
required\n", str[1]);
		exit(255);
	}
	if (str[2])
	{
		ft_printf(2, "minishell: exit: %s: too many arguments\n", str[2]);
		return (1);
	}
	ft_printf(2, "exit\n");
	exit(ft_atoi(str[1] + num_metka));
	return (0);
}
