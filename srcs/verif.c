/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:23:35 by eanne             #+#    #+#             */
/*   Updated: 2024/12/03 16:31:03 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int verif_doublon(int len, char **arg)
{
   int i;
   int j;
   int search;

   i = 1;
   len--;
   while (i <= len)
   {
       j = 1;
       search = atoi(arg[i]);
       while (j <= len)
       {
           if (i != j && search == atoi(arg[j]))
               return (0);
           j++;
       }
       i++;
   }
   return (1);
}