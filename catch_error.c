/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:12:03 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/12 16:40:21 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	catch_error(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack)->next)
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			if ((*stack)->value == tmp->value)
			{
				write (2, "Error\n", 6);
				exit(0);
			}
			tmp = tmp->next;
		}
		stack = &(*stack)->next;
	}
}
