/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:35 by eanne             #+#    #+#             */
/*   Updated: 2025/01/09 18:14:49 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	verif_doublon_int(int len, char **arg)
{
	int			i;
	int			j;
	long int	search;

	i = 1;
	len--;
	while (i <= len)
	{
		if (!is_valid_number(arg[i]))
			return (0);
		j = 1;
		search = ft_atol(arg[i]);
		while (j <= len)
		{
			if (i != j && search == ft_atol(arg[j]))
				return (0);
			if (search > INT_MAX || search < INT_MIN)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_doublon_char(char *argv)
{
	char		**split;
	int			i;
	int			j;
	long int	search;

	split = ft_split(argv, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (free_loop(split));
		j = 0;
		search = ft_atol(split[i]);
		while (split[j])
		{
			if (i != j && search == ft_atol(split[j]))
				return (free_loop(split));
			j++;
		}
		i++;
	}
	free_loop(split);
	return (1);
}

int	is_valid_number(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		len++;
		i++;
	}
	if (len > 10)
		return (0);
	if (len == 10)
	{
		if (str[0] == '-' && ft_strncmp(&str[1], "2147483648", 10) > 0)
			return (0);
		if (str[0] != '-' && ft_strncmp(str, "2147483647", 10) > 0)
			return (0);
	}
	return (1);
}
