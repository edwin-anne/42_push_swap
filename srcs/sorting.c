/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:32 by eanne             #+#    #+#             */
/*   Updated: 2024/12/17 10:57:32 by eanne            ###   ########.fr       */
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
 * Move the element at index to the top of the stack
 */
static void move_to_top(t_list **stack, int index, char stack_name)
{
    int size = ft_lstsize(*stack);

    if (index <= size / 2)
    {
        while (index-- > 0)
            (stack_name == 'a') ? ra(stack) : rb(stack);
    }
    else
    {
        index = size - index;
        while (index-- > 0)
            (stack_name == 'a') ? rra(stack) : rrb(stack);
    }
}

/**
 * Push elements to stack B in small chunks
 */
static void push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
    int chunk_min = 0;
    int chunk_max = chunk_size;
    int total_size = ft_lstsize(*stack_a);

    while (chunk_min < total_size)
    {
        int i = 0;
        int current_size = ft_lstsize(*stack_a);

        while (i++ < current_size)
        {
            int value = *(int *)(*stack_a)->content;
            if (value >= chunk_min && value < chunk_max)
            {
                pb(stack_a, stack_b);
                if (*stack_b && (*(int *)(*stack_b)->content < chunk_min + chunk_size / 2))
                    rb(stack_b);
            }
            else
                ra(stack_a);
        }
        chunk_min += chunk_size;
        chunk_max += chunk_size;
    }
}

/**
 * Return elements to stack A in descending order
 */
static void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        int max_index = 0;
        int max_value = *(int *)(*stack_b)->content;
        t_list *current = *stack_b;

        for (int i = 0; current; i++)
        {
            if (*(int *)current->content > max_value)
            {
                max_value = *(int *)current->content;
                max_index = i;
            }
            current = current->next;
        }
        move_to_top(stack_b, max_index, 'b');
        pa(stack_a, stack_b);
    }
}

/**
 * Optimized function to sort stack A using chunking
 */
void sort_stack(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);
    int chunk_size = (size <= 100) ? 20 : 50;

    push_chunks_to_b(stack_a, stack_b, chunk_size);
    push_back_to_a(stack_a, stack_b);
}

/**
 * Entry point for sorting. To be used in main program.
 */
void push_swap(t_list **stack_a)
{
    t_list *stack_b = NULL;

    if (!is_sorted(*stack_a))
        sort_stack(stack_a, &stack_b);
}
