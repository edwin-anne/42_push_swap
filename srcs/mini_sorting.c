/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:34:31 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2024/12/30 14:00:44 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Mini sorting est un algo parrallèle pour trier avec le moins 
//de coup possible si c'est la taille est de moins de 5 args
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

/*
Si il y a 3 arguments faire des conditions de 
supérieur - inférieur pour intérvertir les arg 
pour les mettre a la bonne place
*/
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

/*
La fonction sépare en deux les elements dans la stack pour le tri
par 5 pour faire un tri dans la stack b de 2 elements et de 3
elements dans la stack a
*/
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

/*
Cette fonction fait un tri dans la stack a et b pour trier les elements
et ensuite fusionne les 2 stacks dans a
*/
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

/*
Cette fonction est pour le tri par 5 elements
*/
void	mini_sorting_5(t_list **stack_a, t_list **stack_b)
{
	move_min_to_b(stack_a, stack_b);
	sort_and_merge(stack_a, stack_b);
}
