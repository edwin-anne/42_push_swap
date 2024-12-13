/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:32 by eanne             #+#    #+#             */
/*   Updated: 2024/12/13 16:38:42 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * Function to check if the stack is sorted
 */
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
 * Function to find the position of the largest element in a stack
 */
static int find_max_position(t_list *stack)
{
    int max;
    int position;
    int max_position;
    t_list *current;

    current = stack;
    max = *(int *)current->content;
    position = 0;
    max_position = 0;

    while (current)
    {
        if (*(int *)current->content > max)
        {
            max = *(int *)current->content;
            max_position = position;
        }
        current = current->next;
        position++;
    }
    return (max_position);
}

/**
 * Helper function to push elements of a chunk to stack B
 */
static void push_chunk_to_b(t_list **stack_a, t_list **stack_b, int min, int max)
{
    int size = ft_lstsize(*stack_a);

    for (int i = 0; i < size; i++)
    {
        int value = *(int *)(*stack_a)->content;
        if (value >= min && value <= max)
        {
            pb(stack_a, stack_b);
        }
        else
        {
            ra(stack_a);
        }
    }
}

/**
 * Optimized function to sort stack A using chunks
 */
void sort_stack(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);
    int chunk_count = 5;
    int chunk_size = (size + chunk_count - 1) / chunk_count; // Dynamically distribute chunks

    for (int i = 0; i < chunk_count; i++)
    {
        int min = i * chunk_size;
        int max = (i + 1) * chunk_size - 1;
        if (max >= size)
            max = size - 1;
        push_chunk_to_b(stack_a, stack_b, min, max);
    }

    while (*stack_b)
    {
        int max_pos = find_max_position(*stack_b);
        if (max_pos <= ft_lstsize(*stack_b) / 2)
        {
            while (max_pos-- > 0)
                rb(stack_b);
        }
        else
        {
            max_pos = ft_lstsize(*stack_b) - max_pos;
            while (max_pos-- > 0)
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

/**
 * Entry point for sorting. To be used in main program.
 */
void push_swap(t_list **stack_a)
{
    t_list *stack_b;

    stack_b = NULL;
    if (!is_sorted(*stack_a))
        sort_stack(stack_a, &stack_b);
}
