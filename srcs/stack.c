/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:09:30 by eanne             #+#    #+#             */
/*   Updated: 2024/12/28 10:16:04 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>


t_list *create_element(void *content)
{
    t_list *new_element;

    new_element = (t_list *)malloc(sizeof(t_list));
    if (!new_element)
        return (NULL);
    new_element->content = content;
    new_element->next = NULL;
    new_element->previous = NULL;
    new_element->index = 0;
    new_element->position = -1;
    new_element->marked = 0;
    new_element->distance = 0;
    return (new_element);
}

t_list	*create_stack_null()
{
	return (NULL);
}

void append(t_list **stack, void *content)
{
    t_list *new_element = create_element(content);
    t_list *current = *stack;

    if (!new_element)
        return;

    if (!(*stack)) {
        *stack = new_element;
        return;
    }

    while (current->next)
        current = current->next;

    current->next = new_element;
    new_element->previous = current;
    new_element->index = current->index + 1;
}

int initialize_stack(t_list **stack, char **argv, int start)
{
    int i;
    long int *content;

    i = start;
    while (argv[i]) {
        content = malloc(sizeof(long int));
        if (!content)
            return (0);
        *content = ft_atol(argv[i]);
        if (i == start)
            *stack = create_element(content);
        else
            append(stack, content);
        i++;
    }
    return (1);
}

int initialize_stack_char(t_list **stack, char *argv)
{
    char **split;
    int i;
    long int *content;

    split = ft_split(argv, ' ');
    if (!split)
        return (0);
    i = 0;
    while (split[i]) {
        content = malloc(sizeof(long int));
        if (!content)
            return (free_loop(split));
        *content = ft_atol(split[i]);
        if (i == 0)
            *stack = create_element(content);
        else
            append(stack, content);
        i++;
    }
    free_loop(split);
    return (1);
}

void	*pop(t_list **stack)
{
    if (!*stack)
        return (NULL);
    t_list *top = *stack;
    void *content = top->content;

    *stack = top->next;
    if (*stack)
        (*stack)->previous = NULL;
    free(top);
    return content;
}

void *peek(t_list *stack)
{
    if (!stack)
        return NULL;
    return stack->content;
}

int is_empty(t_list *stack)
{
    return stack == NULL;
}
