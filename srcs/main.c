/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:28:19 by eanne             #+#    #+#             */
/*   Updated: 2024/12/12 13:42:33 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int verif_and_insert(int argc, char **argv, t_list **stack_a)
{
	if (character_detector(argv))
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

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	int *test = malloc(sizeof(int));
	if (test == NULL)
	{
		perror("Allocation failed");
		exit(EXIT_FAILURE);
	}
	*test = 1;

	stack_b = create_element(test);
	if (verif_and_insert(argc, argv, &stack_a))
	{
		printf("STACK A || ");
		print_stack(stack_a);
		printf("\nSTACK B || ");
		print_stack(stack_b);
		printf("\n** OPERATIONS **\n\n");
		pa(&stack_b, &stack_a);
		
		printf("STACK A || ");
		print_stack(stack_a);
		printf("\nSTACK B || ");
		print_stack(stack_b);
	}
	else
		write(2, "Error\n", 6);
}
