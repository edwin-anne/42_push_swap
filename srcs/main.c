/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:28:19 by eanne             #+#    #+#             */
/*   Updated: 2024/12/11 21:24:59 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_list *stack_a;
	if (character_detector(argv))
	{
		if (argc > 2)
		{
			if (verif_doublon_int(argc, argv))
			{
				initialize_stack(&stack_a, argv, 1);
			}
			else
				write(2, "Error\n", 6);
		}
		else
		{
			if (verif_doublon_char(argv[1]))
			{
				printf("ok");
			}
			else
				write(2, "Error\n", 6);
		}
	}
	else
		write(2, "Error\n", 6);

	print_stack(stack_a);
}
