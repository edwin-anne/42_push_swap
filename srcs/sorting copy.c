/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:32 by eanne             #+#    #+#             */
/*   Updated: 2024/12/27 23:24:36 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
#include <limits.h>

static int find_max_value(t_list *stack)
{
    int max_val = INT_MIN;
    while (stack)
    {
        int val = *(int *)stack->content;
        if (val > max_val)
            max_val = val;
        stack = stack->next;
    }
    return max_val;
}

static int find_second_max_value(t_list *stack)
{
    int max_val = INT_MIN;
    int second_max_val = INT_MIN;

    while (stack)
    {
        int val = *(int *)stack->content;
        if (val > max_val)
        {
            second_max_val = max_val;
            max_val = val;
        }
        else if (val > second_max_val && val < max_val)
        {
            second_max_val = val;
        }
        stack = stack->next;
    }
    return second_max_val;
}

static int find_position_of_value(t_list *stack, int value)
{
    int pos = 0;
    while (stack)
    {
        if (*(int *)stack->content == value)
            return pos;
        stack = stack->next;
        pos++;
    }
    return -1;
}

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

int find_min(t_list *stack)
{
    if (!stack)
        return 0;

    int min = *((int *)stack->content);

    while (stack)
    {
        int value = *((int *)stack->content);
        if (value < min)
            min = value;
        stack = stack->next;
    }

    return min;
}

static void push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
    int chunk_min = find_min(*stack_a);
    int chunk_max = find_min(*stack_a) + chunk_size;
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
static int try_push_next(t_list **stack_b, t_list **stack_a, int swap)
{
    int second_max_val = find_second_max_value(*stack_b);

    if (*(int *)(*stack_b)->content == second_max_val && !swap)
    {
        pa(stack_a, stack_b);
        return 1;
    }
    return 0;
}


int smart_rotate_b(t_list **stack_b, int size_b, t_list **stack_a)
{
    if (!stack_b || !*stack_b || size_b <= 0)
        return 0;

    int swap = 0;
    int max_val = find_max_value(*stack_b);
    int cnt = find_position_of_value(*stack_b, max_val);
    int mid = size_b / 2;

    if (cnt < 0)
        return swap;

    while (*(int *)(*stack_b)->content != max_val)
    {
        if (!try_push_next(stack_b, stack_a, swap))
        {
            if (cnt > mid)
                rrb(stack_b);
            else
                rb(stack_b);
        }
        else
        {
            swap = 1;
        }
    }
    return swap;
}

static void push_back_to_a(t_list **stack_a, t_list **stack_b)
{
    while (*stack_b)
    {
        if (smart_rotate_b(stack_b, ft_lstsize(*stack_b), stack_a))
        {
            pa(stack_a, stack_b);

            if (*stack_b && (*stack_b)->next &&
                *(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
                ss(stack_a, stack_b);
            else
                sa(stack_a);
        }
        else
            pa(stack_a, stack_b);
    }
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
    int size = ft_lstsize(*stack_a);
    int chunk_size = size / 12 + 22;

    push_chunks_to_b(stack_a, stack_b, chunk_size);

    push_back_to_a(stack_a, stack_b);

    if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
        ra(stack_a);
}

void push_swap(t_list **stack_a)
{
    t_list *stack_b = NULL;

    if (!is_sorted(*stack_a))
    {
        if (ft_lstsize(*stack_a) > 5)
            sort_stack(stack_a, &stack_b);
        else
            mini_sorting(stack_a, &stack_b);
    }
    //print_stack(*stack_a);
}
