/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:32 by eanne             #+#    #+#             */
/*   Updated: 2025/01/10 22:04:34 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#include <limits.h>

//Verifie si la valeur qu'il reste sur stack b est le suivant
// qui est a deplace dans la stack a
static int	try_push_next(t_list **stack_b, t_list **stack_a, int swap)
{
	int	second_max_val;

	second_max_val = find_second_max_value(*stack_b);
	if (*(int *)(*stack_b)->content == second_max_val && !swap)
	{
		pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

//Deplace dans la stack b lélement qui est le suivant a push dans la stack a
//Appelle try_push_next pour savoir si on peux push
int	smart_rotate_b(t_list **stack_b, int size_b, t_list **stack_a)
{
	int	swap;
	int	max_val;
	int	cnt;
	int	mid;

	swap = 0;
	max_val = find_max_value(*stack_b);
	cnt = find_position_of_value(*stack_b, max_val);
	mid = size_b / 2;
	if (!stack_b || !*stack_b || size_b <= 0 || cnt < 0)
		return (0);
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
			swap = 1;
	}
	return (swap);
}

//2eme parti du tri avec les chunks qui sont trie
//il faut les parcourire pour push le prochain element
static void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		if (smart_rotate_b(stack_b, ft_lstsize(*stack_b), stack_a))
		{
			pa(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next
				&& *(int *)(*stack_b)->content
				< *(int *)(*stack_b)->next->content)
				ss(stack_a, stack_b);
			else
				sa(stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
}

//Fonction principal qui calcule la taille des chunks
//et appelle les 2 etapes du tri par chunks
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	chunk_size;

	size = ft_lstsize(*stack_a);
	chunk_size = size / 12 + 22;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		ra(stack_a);
}

//Verifie si la pile n'est pas deja triee
//Sinon appelle le tri
void	push_swap(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) > 5)
			sort_stack(stack_a, &stack_b);
		else
			mini_sorting(stack_a, &stack_b);
	}
	free_list(*stack_a);
	free_list(stack_b);
}
