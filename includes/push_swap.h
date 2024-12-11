/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:19:27 by eanne             #+#    #+#             */
/*   Updated: 2024/12/11 21:05:32 by eanne            ###   ########.fr       */
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
void initialize_stack(t_list **stack, char **argv, int start);
void *pop(t_list **stack);
void *peek(t_list *stack);
int is_empty(t_list *stack);
void print_stack(t_list *stack);


#endif