/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:55:43 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:53:44 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		return ;
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*current;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		return ;
	}
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	push_stack(t_list **from, t_list **to)
{
	t_list	*node;

	if (!from || !(*from))
	{
		return ;
	}
	node = *from;
	*from = node->next;
	node->next = *to;
	*to = node;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		return ;
	}
	first = *stack;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}
