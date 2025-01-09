/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:20:16 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/09 14:42:33 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks_to_b_helper(t_list **stack_a, t_list **stack_b,
									t_chunk_limits *limits, int *count)
{
	int	value;
	int	position;
	int	lower_limit;
	int	upper_limit;

	value = *(int *)(*stack_a)->content;
	lower_limit = limits->lower_limit;
	upper_limit = limits->upper_limit;
	if (value >= lower_limit && value < upper_limit)
	{
		pb(stack_a, stack_b);
		(*count)++;
		if (*(int *)(*stack_b)->content <
			(lower_limit + limits->chunk_size / 2))
			rb(stack_b);
	}
	else
	{
		position = find_position_in_stack(*stack_a, lower_limit, upper_limit);
		if (position > ft_lstsize(*stack_a) / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int				chunk_n;
	int				count;
	int				total_elements;
	t_chunk_limits	limits;

	chunk_n = 1;
	count = 0;
	total_elements = ft_lstsize(*stack_a);
	while (count < total_elements)
	{
		limits.upper_limit = chunk_size * chunk_n;
		limits.lower_limit = limits.upper_limit - chunk_size;
		limits.chunk_size = chunk_size;
		if (count_elements_in_chunk(*stack_a,
				limits.lower_limit, limits.upper_limit) == 0)
		{
			chunk_n++;
			continue ;
		}
		push_chunks_to_b_helper(stack_a, stack_b, &limits, &count);
	}
}

int	find_position_in_stack(t_list *stack, int lower_limit, int upper_limit)
{
	int	position;
	int	value;

	position = 0;
	while (stack)
	{
		value = *(int *)stack->content;
		if (value >= lower_limit && value < upper_limit)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

int	count_elements_in_chunk(t_list *stack, int lower_limit, int upper_limit)
{
	int	count;
	int	value;

	count = 0;
	while (stack)
	{
		value = *(int *)stack->content;
		if (value >= lower_limit && value < upper_limit)
			count++;
		stack = stack->next;
	}
	return (count);
}
