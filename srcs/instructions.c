/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:32:13 by eanne             #+#    #+#             */
/*   Updated: 2024/12/12 13:32:29 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Swap for stack a
void sa(t_list **a)
{
    swap(a);
}

// Swap for stack b
void sb(t_list **b)
{
    swap(b);
}

// Swap both stacks
void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
}

void pa(t_list **b, t_list **a)
{
    push(b, a);
}

void pb(t_list **a, t_list **b)
{
    push(a, b);
}

void ra(t_list **a)
{
    rotate(a);
}

void rb(t_list **b)
{
    rotate(b);
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
}

void rra(t_list **a)
{
    reverse_rotate(a);
}

void rrb(t_list **b)
{
    reverse_rotate(b);
}

void rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}