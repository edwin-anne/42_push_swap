/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:46:49 by eanne             #+#    #+#             */
/*   Updated: 2024/12/11 21:16:04 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
long int	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

int character_detector(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

    while (argv[i] != NULL) {
        j = 0;
        while (argv[i][j] != '\0') {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ') {
                return (0);
            }
            j++;
        }
        i++;
    }

    return (1);
}
