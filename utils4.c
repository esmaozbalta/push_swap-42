/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:23:37 by esozbalt          #+#    #+#             */
/*   Updated: 2024/05/17 18:55:02 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack) // son elemanı en başa taşır
{
	t_stack	*newstart;
	t_stack	*newend;

	if (ft_lstsize(*stack) < 2)
		return ;
	newstart = ft_lstlast(*stack); //son eleman atılır
	newend = *stack; //ilk eleman atılır
	while (newend->next->next)
		newend = newend->next;
	newend->next = NULL;
	newstart->next = *stack;
	*stack = newstart;
}

void	rra(t_stack **a_stack)
{
	reverse_rotate(a_stack);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b_stack)
{
	reverse_rotate(b_stack);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a_stack, t_stack **b_stack)
{
	if ((ft_lstsize(*a_stack) < 2) || (ft_lstsize(*b_stack) < 2))
		return ;
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	write (1, "rrr\n", 4);
}
