/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixbin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:56:58 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/12 17:18:13 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min2(t_stack	**stack_a)
{
	t_stack	*tmp;
	t_stack	*min;
	int		x;

	x = 0;
	tmp = *stack_a;
	min = NULL;
	while (tmp)
	{
		if ((!x || tmp->value < min->value) && (tmp->index == -1))
		{
			x = 1;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	index_setter(t_stack	**stack_a)
{
	t_stack	*min;
	int		i;

	min = find_min2(stack_a);
	i = 0;
	while (min)
	{
		min->index = i;
		i++;
		min = find_min2(stack_a);
	}
}

void	radixbin(t_stack	**stack_a, t_stack	**stack_b)
{
	int	push;
	int	len;

	push = 0;
	index_setter(stack_a);
	while (!check_sorted(stack_a))
	{
		len = ft_lstsize(*stack_a);
		while (len)
		{
			if ((((*stack_a)->index >> push) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			len--;
		}
		push++;
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
