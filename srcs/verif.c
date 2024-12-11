/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:35 by eanne             #+#    #+#             */
/*   Updated: 2024/12/11 22:08:34 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	verif_doublon_int(int len, char **arg)
{
	int			i;
	int			j;
	long int	search;

	i = 1;
	len--;
	while (i <= len)
	{
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
	char	**split;
	int		i;
	int		j;
	int		search;

	split = ft_split(argv, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		j = 0;
		search = ft_atol(split[i]);
		while (split[j])
		{
			if (i != j && search == ft_atol(split[j]))
				return (free_loop(split));
			if (search > INT_MAX || search < INT_MIN)
				return (free_loop(split));
			j++;
		}
		i++;
	}
	return (free_loop(split));
}

int	free_loop(char **var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		free(var[i]);
		i++;
	}
	free(var);
	return (0);
}
