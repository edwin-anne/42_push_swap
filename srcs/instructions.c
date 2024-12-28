/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:32:13 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:13:36 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void sa(t_list **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void sb(t_list **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}

void pa(t_list **a, t_list **b)
{
    push_stack(b, a);
    write(1, "pa\n", 3);
}

void pb(t_list **a, t_list **b)
{
    push_stack(a, b);
    write(1, "pb\n", 3);
}

void ra(t_list **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_list **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void rra(t_list **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rrb(t_list **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}
