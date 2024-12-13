/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:32 by eanne             #+#    #+#             */
/*   Updated: 2024/12/13 11:41:43 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int is_sorted(t_list *stack)
{
    if (!stack || !stack->next)
        return (1);

    while (stack->next)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/**
 * Function to find the position of the smallest element in a stack
 */
static int find_min_position(t_list *stack)
{
    int min;
    int position;
    int min_position;
    t_list *current;

    current = stack;
    min = *(int *)current->content;
    position = 0;
    min_position = 0;

    while (current)
    {
        if (*(int *)current->content < min)
        {
            min = *(int *)current->content;
            min_position = position;
        }
        current = current->next;
        position++;
    }
    return (min_position);
}

/**
 * Function to sort stack A using stack B as helper
 */
void sort_stack(t_list **stack_a, t_list **stack_b)
{
    int min_pos;
    int size;

    size = ft_lstsize(*stack_a);
    while (size > 0)
    {
        min_pos = find_min_position(*stack_a);
        if (min_pos <= size / 2)
        {
            while (min_pos-- > 0)
                ra(stack_a);
        }
        else
        {
            min_pos = size - min_pos;
            while (min_pos-- > 0)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
        size--;
    }

    while (*stack_b)
    {
        pa(stack_a, stack_b);
    }
}

/**
 * Entry point for sorting. To be used in main program.
 */
void push_swap(t_list **stack_a)
{
    t_list *stack_b;

    stack_b = create_stack_null();
    if (!is_sorted(*stack_a))
        sort_stack(stack_a, &stack_b);
}
