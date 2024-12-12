/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:27 by eanne             #+#    #+#             */
/*   Updated: 2024/12/12 13:35:58 by eanne            ###   ########.fr       */
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
int free_loop(char **var);
long int	ft_atol(const char *str);
int	character_detector(char **argv);

//******************//
//***** STACK ******//
//******************//

void push(t_list **stack, void *content);
t_list *create_element(void *content);
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
void sa(t_list **a);
void sb(t_list **b);
void ss(t_list **a, t_list **b);
void pa(t_list **b, t_list **a);
void pb(t_list **a, t_list **b);
void ra(t_list **a);
void rb(t_list **b);
void rr(t_list **a, t_list **b);
void rra(t_list **a);
void rrb(t_list **b);
void rrr(t_list **a, t_list **b);


#endif