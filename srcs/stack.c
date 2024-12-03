/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:33:00 by eanne             #+#    #+#             */
/*   Updated: 2024/12/02 10:55:47 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Allouer de la mémoire pour la structure t_stack
//Allouer de la mémoire pour le tableau d'entiers de la pile
//Libérer la mémoire de la structure si l'allocation échoue
//Initialiser les champs
//La pile est vide, donc `top` commence à -1
//Taille maximale de la pile
t_stack *init_stack(int size)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->array = (int *)malloc(size * sizeof(int));
    if (!stack->array)
        return (free(stack));
    stack->top = -1;
    stack->size = size;
    return (stack);
}

// Si la pile est NULL, rien à libérer
// Libérer le tableau dynamique utilisé par la pile
// Libérer la structure elle-même
void free_stack(t_stack *stack)
{
    if (!stack)
        return; 
    if (stack->array)
        free(stack->array);
    free(stack);
}
