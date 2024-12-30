/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:28:19 by eanne             #+#    #+#             */
/*   Updated: 2024/12/30 13:52:50 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Vérifie si il y a un caractère dans les arguments et initialise les stacks
//selon les données transmise
int	verif_and_insert(int argc, char **argv, t_list **stack_a)
{
	if (character_detector(argv, 1, 0))
	{
		if (argc > 2)
		{
			if (verif_doublon_int(argc, argv))
				return (initialize_stack(stack_a, argv, 1));
			else
				return (0);
		}
		else
		{
			if (verif_doublon_char(argv[1]))
				return (initialize_stack_char(stack_a, argv[1]));
			else
				return (0);
		}
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (verif_and_insert(argc, argv, &stack_a))
	{
		push_swap(&stack_a);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
