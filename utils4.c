/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:23:37 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/12 18:38:15 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*newstart;
	t_stack	*newend;

	if (ft_lstsize(*stack) < 2)
		return ;
	newstart = ft_lstlast(*stack);
	newend = *stack;
	while (newend->next->next)
		newend = newend->next;
	newend->next = NULL;
	newstart->next = *stack;
	*stack = newstart;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 && ft_lstsize(*stack_b) < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
