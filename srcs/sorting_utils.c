/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:52:54 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2024/12/28 20:56:02 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
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

int	find_min(t_list *stack)
{
	int	min;
	int	value;

	if (!stack)
		return (0);
	min = *((int *)stack->content);
	while (stack)
	{
		value = *((int *)stack->content);
		if (value < min)
			min = value;
		stack = stack->next;
	}
	return (min);
}

int	find_max_value(t_list *stack)
{
	int	max_val;
	int	val;

	max_val = INT_MIN;
	while (stack)
	{
		val = *(int *)stack->content;
		if (val > max_val)
			max_val = val;
		stack = stack->next;
	}
	return (max_val);
}

int	find_second_max_value(t_list *stack)
{
	int	max_val;
	int	second_max_val;
	int	val;

	max_val = INT_MIN;
	second_max_val = INT_MIN;
	while (stack)
	{
		val = *(int *)stack->content;
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
	return (second_max_val);
}

int	find_position_of_value(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
