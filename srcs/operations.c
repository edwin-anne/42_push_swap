/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:55:43 by eanne             #+#    #+#             */
/*   Updated: 2024/12/12 13:35:50 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Swap the first two elements of a stack
void swap(t_list **stack) {
    if (!stack || !(*stack) || !((*stack)->next)) {
        return;
    }
    t_list *first = *stack;
    t_list *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

// Reverse rotate operation
void reverse_rotate(t_list **stack) {
    if (!stack || !(*stack) || !((*stack)->next)) {
        return;
    }
    t_list *prev = NULL;
    t_list *current = *stack;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

// Push operation
void push_stack(t_list **from, t_list **to) {
    if (!from || !(*from)) {
        return;
    }
    t_list *node = *from;
    *from = node->next;
    node->next = *to;
    *to = node;
}

// Rotate operation
void rotate(t_list **stack) {
    if (!stack || !(*stack) || !((*stack)->next)) {
        return;
    }
    t_list *first = *stack;
    t_list *last = *stack;
    while (last->next) {
        last = last->next;
    }
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}