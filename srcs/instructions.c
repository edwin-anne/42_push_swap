/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:32:13 by eanne             #+#    #+#             */
/*   Updated: 2024/12/13 11:47:05 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
// Swap for stack a
void sa(t_list **a)
{
    swap(a);
    printf("sa\n");
}

// Swap for stack b
void sb(t_list **b)
{
    swap(b);
    printf("sb\n");
}

// Swap both stacks
void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}

void pa(t_list **a, t_list **b)
{
    push_stack(b, a);
    printf("pa\n");
}

void pb(t_list **a, t_list **b)
{
    push_stack(a, b);
    printf("pb\n");
}

void ra(t_list **a)
{
    rotate(a);
    printf("ra\n");
}

void rb(t_list **b)
{
    rotate(b);
    printf("rb\n");
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}

void rra(t_list **a)
{
    reverse_rotate(a);
    printf("rra\n");
}

void rrb(t_list **b)
{
    reverse_rotate(b);
    printf("rrb\n");
}

void rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}