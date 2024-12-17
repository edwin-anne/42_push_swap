/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:09:30 by eanne             #+#    #+#             */
/*   Updated: 2024/12/17 10:51:42 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

// Cree la stack
t_list *create_element(void *content)
{
    t_list *new_element;

    new_element = (t_list *)malloc(sizeof(t_list));
    if (!new_element)
        return (NULL);
    new_element->content = content;
    new_element->next = NULL;
    new_element->previous = NULL;
    new_element->index = 0;       // Initialisation de l'index
    new_element->position = -1;   // Position initiale inconnue
    new_element->marked = 0;      // Non marqué
    new_element->distance = 0;    // Distance à 0
    return (new_element);
}

// Cree la stack NULL
t_list	*create_stack_null()
{
	return (NULL);
}

// Ajoute un élément à la fin de la pile
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
    new_element->index = current->index + 1; // Mise à jour de l'index
}

// Initialise la stack en ajoutant les arguments de argv dans la stack
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

// Fonction qui ajoute les valeurs dans la stack quand un char est donné comme arg
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

// Fonction pour retirer l’élément au sommet de la pile (Pop)
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
    while (stack) {
        printf("%d -> ", *(int *)stack->content); // Assurez-vous que `content` contient bien un entier.
        stack = stack->next;
    }
    printf("NULL\n");
}
