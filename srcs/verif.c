/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:35 by eanne             #+#    #+#             */
/*   Updated: 2024/12/05 18:46:11 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	verif_doublon_int(int len, char **arg)
{
	int	i;
	int	j;
	int	search;

	i = 1;
	len--;
	while (i <= len)
	{
		j = 1;
		search = ft_atoi(arg[i]);
		while (j <= len)
		{
			if (i != j && search == ft_atoi(arg[j]))
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
		search = ft_atoi(split[i]);
		while (split[j])
		{
			if (i != j && search == ft_atoi(split[j]))
			{
				while (split[i])
					free(split[i++]);
				free(split);
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (1);
}
