/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:34:31 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2024/12/28 21:07:18 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sorting(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		mini_sorting_3(stack_a);
	else
		mini_sorting_5(stack_a, stack_b);
}

void	mini_sorting_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
	if (a > b && b < c && c > a)
		sa(stack_a);
	else if (a > b && b > c && c < a)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && c < a)
		ra(stack_a);
	else if (a < b && b > c && c > a)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && c < a)
		rra(stack_a);
}

void	move_min_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	pos;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = find_min(*stack_a);
		pos = find_position_of_value(*stack_a, min);
		size = ft_lstsize(*stack_a);
		if (pos <= size / 2)
		{
			while (*(int *)(*stack_a)->content != min)
				ra(stack_a);
		}
		else
		{
			while (*(int *)(*stack_a)->content != min)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	sort_and_merge(t_list **stack_a, t_list **stack_b)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
	if (*(int *)(*stack_a)->next->content
		> *(int *)(*stack_a)->next->next->content)
	{
		rra(stack_a);
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b);
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	}
}

void	mini_sorting_5(t_list **stack_a, t_list **stack_b)
{
	move_min_to_b(stack_a, stack_b);
	sort_and_merge(stack_a, stack_b);
}
