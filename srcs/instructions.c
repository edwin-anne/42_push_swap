/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:32:13 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:40:06 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pa(t_list **a, t_list **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
