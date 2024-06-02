/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:25:01 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 20:14:33 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)//yığının (stack) ilk elemanını sonuna taşır
{
	t_stack *start;
	t_stack *end;
	
	if (ft_lstsize(*stack) < 2)
		return ;
	start = *stack; //startın adresi artık stackin ilk elemanını gösterir
	end = ft_lstlast(*stack); //son elemanın adresini end e atar
	*stack = (*stack)->next; //stacke (ilk eleman) 2. elemanın adresi atılır yani artık 2. eleman en başa geçer 
	end->next = start; // sondan sonraki eleman start ı işaret eder.
	start->next = NULL; //start elemanı artık son eleman olduğu için ondan sonraki eleman NULL olur
}

void	ra(t_stack **a_stack)
{
	rotate(a_stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b_stack)
{
	rotate(b_stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a_stack, t_stack **b_stack)
{
	if ((ft_lstsize(*a_stack) < 2) || (ft_lstsize(*b_stack) < 2))
		return ;
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
}
