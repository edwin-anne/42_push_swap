/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:28:19 by eanne             #+#    #+#             */
/*   Updated: 2024/12/05 18:49:36 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		if (verif_doublon_int(argc, argv))
		{
			printf("ok");
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
