/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:46:49 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:03:22 by Edwin ANNE       ###   ########.fr       */
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
    int i;
    int j;

    i = 1;
    while (argv[i] != NULL) {
        if (argv[i][0] == '\0') {
            return (0);
        }
        j = 0;
        while (argv[i][j] != '\0') {
            if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' ') {
                return (0);
            }
            // Vérification des signes + et -
            if ((argv[i][j] == '-' || argv[i][j] == '+')) {
                if (j > 0 && argv[i][j - 1] != ' ') {
                    return (0); // Le signe doit être précédé d'un espace ou au début
                }
                if (argv[i][j + 1] == '\0' || (argv[i][j + 1] < '0' || argv[i][j + 1] > '9')) {
                    return (0); // Le signe doit être suivi d'un chiffre
                }
            }
            j++;
        }
        i++;
    }

    return (1);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
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

void free_list(t_list *list)
{
    t_list *temp;

    while (list != NULL)
    {
        temp = list->next;
        free(list->content);
        free(list);
        list = temp;
    }
}