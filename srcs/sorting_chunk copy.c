/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:20:16 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2024/12/28 09:39:58 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
    int chunk_n = 1;
    int count = 0;
    int total_elements = ft_lstsize(*stack_a);

    while (count < total_elements)
    {
        int value = *(int *)(*stack_a)->content;
        int upper_limit = chunk_size * chunk_n;
        int lower_limit = upper_limit - chunk_size;

        if (value >= lower_limit && value < upper_limit)
        {
            pb(stack_a, stack_b);
            count++;
            if (*(int *)(*stack_b)->content < (lower_limit + chunk_size / 2))
                rb(stack_b);
        }
        else
        {
            int position = find_position_in_stack(*stack_a, lower_limit, upper_limit);
            if (position > total_elements / 2)
                rra(stack_a);
            else
                ra(stack_a);
        }

        if (count_elements_in_chunk(*stack_a, lower_limit, upper_limit) == 0)
            chunk_n++;
    }
}

int find_position_in_stack(t_list *stack, int lower_limit, int upper_limit)
{
    int position = 0;
    while (stack)
    {
        int value = *(int *)stack->content;
        if (value >= lower_limit && value < upper_limit)
            return position;
        position++;
        stack = stack->next;
    }
    return -1;
}

int count_elements_in_chunk(t_list *stack, int lower_limit, int upper_limit)
{
    int count = 0;
    while (stack)
    {
        int value = *(int *)stack->content;
        if (value >= lower_limit && value < upper_limit)
            count++;
        stack = stack->next;
    }
    return count;
}