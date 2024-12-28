/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:27 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:02:48 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stddef.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
	int				position;
	int				marked;
	int				distance;
}	t_list;

//******************//
//***** MAIN *******//
//******************//
int	verif_and_insert(int argc, char **argv, t_list **stack_a);

//******************//
//***** PARSING ****//
//******************//

int	verif_doublon_int(int len, char **arg);
int	verif_doublon_char(char *argv);
long int	ft_atol(const char *str);
int	character_detector(char **argv);
int		ft_lstsize(t_list *lst);

//******************//
//***** STACK ******//
//******************//

void append(t_list **stack, void *content);
t_list *create_element(void *content);
t_list	*create_stack_null();
int initialize_stack(t_list **stack, char **argv, int start);
int initialize_stack_char(t_list **stack, char *argv);
void *pop(t_list **stack);
void *peek(t_list *stack);
int is_empty(t_list *stack);
void print_stack(t_list *stack);

//***********************//
//***** OPERATIONS ******//
//***********************//
void swap(t_list **stack);
void reverse_rotate(t_list **stack);
void push_stack(t_list **from, t_list **to);
void rotate(t_list **stack);

//**************************//
//***** INSTRUCTIONS ******//
//*************************//
void sa(t_list **a); //OK
void sb(t_list **b); //OK
void ss(t_list **a, t_list **b); //OK
void pa(t_list **a, t_list **b); //OK
void pb(t_list **a, t_list **b); //OK
void ra(t_list **a); //OK
void rb(t_list **b); //OK
void rr(t_list **a, t_list **b); //OK
void rra(t_list **a); //OK
void rrb(t_list **b); //OK
void rrr(t_list **a, t_list **b); //OK

//**************************//
//***** SORTING CHUNK ************//
//*************************//
void push_chunks_to_b(t_list **stack_a, t_list **stack_b, int chunk_size);
int find_position_in_stack(t_list *stack, int lower_limit, int upper_limit);
int count_elements_in_chunk(t_list *stack, int lower_limit, int upper_limit);


//**************************//
//***** SORTING ************//
//*************************//
void sort_stack(t_list **stack_a, t_list **stack_b);
void push_swap(t_list **stack_a);
int is_sorted(t_list *stack);
int find_min(t_list *stack);

//**************************//
//***** MINI SORTING ************//
//*************************//
void	mini_sorting(t_list **stack_a, t_list **stack_b);
void    mini_sorting_3(t_list **stack_a);
void mini_sorting_5(t_list **stack_a, t_list **stack_b);

//**************************//
//***** FREE ************//
//*************************//
void free_list(t_list *list);
int free_loop(char **var);
void debug_stack(t_list *stack_a);

#endif