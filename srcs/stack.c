/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:09:30 by eanne             #+#    #+#             */
/*   Updated: 2024/12/11 21:14:44 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "libft.h"
#include <stdio.h>
// Fonction pour créer un nouvel élément
t_list *create_element(void *content)
{
    t_list *new_element = (t_list *)malloc(sizeof(t_list));
    if (!new_element)
        return NULL;
    new_element->content = content;
    new_element->next = NULL;
    return new_element;
}

// Fonction pour ajouter un élément au sommet de la pile (Push)
void push(t_list **stack, void *content)
{
    t_list *new_element = create_element(content);
    if (!new_element)
        return;
    new_element->next = *stack;
    *stack = new_element;
}
void initialize_stack(t_list **stack, char **argv, int start)
{
    int i = start;
    while (argv[i])
    {
        long int *content = malloc(sizeof(long int));
        if (!content)
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        *content = ft_atol(argv[i]);
        if (i == start)
            *stack = create_element(content);
        else
            push(stack, content);
        i++;
    }
}

// Fonction pour retirer l’élément au sommet de la pile (Pop)
void *pop(t_list **stack)
{
    if (!*stack)
        return NULL;
    t_list *top = *stack;
    void *content = top->content;
    *stack = top->next;
    free(top);
    return content;
}

// Fonction pour voir le sommet de la pile (Peek)
void *peek(t_list *stack)
{
    if (!stack)
        return NULL;
    return stack->content;
}

// Fonction pour vérifier si la pile est vide
int is_empty(t_list *stack)
{
    return stack == NULL;
}

// Fonction d’affichage pour les données (Exemple pour des entiers)
void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%ld -> ", *(long int *)(stack->content));
        stack = stack->next;
    }
    printf("NULL\n");
}
