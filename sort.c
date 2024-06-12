/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:57:03 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/12 17:50:05 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selectsort(t_stack **stack_a, t_stack **stack_b, int len)
{
	if (len == 2)
		sa(stack_a);
	if (len == 3)
		sort_3(stack_a);
	if (len == 4)
		sort_4(stack_a, stack_b);
	if (len == 5)
		sort_5(stack_a, stack_b);
	if (len > 5)
		radixbin(stack_a, stack_b);
}

int	find_min(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = (*stack_a)->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_3(t_stack **stack_a)
{
	index_setter(stack_a);
	if ((*stack_a)->index == 2)
		ra(stack_a);
	else if ((*stack_a)->next->index == 2)
		rra(stack_a);
	if (!check_sorted(stack_a))
		sa(stack_a);
}

void	sort_4(t_stack	**stack_a, t_stack **stack_b)
{
	int		min;
	int		len;
	t_stack	*tmp;

	len = lenstack(stack_a);
	min = find_min(stack_a);
	tmp = *stack_a;
	while (len > 0)
	{
		tmp = *stack_a;
		if (tmp->value == min)
		{
			pb(stack_b, stack_a);
			break ;
		}
		rra(stack_a);
		len--;
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack	**stack_a, t_stack	**stack_b)
{
	int		min;
	int		len;
	t_stack	*tmp;

	len = lenstack(stack_a);
	min = find_min(stack_a);
	tmp = *stack_a;
	while (len > 0)
	{
		tmp = *stack_a;
		if (tmp->value == min)
		{
			pb(stack_b, stack_a);
			break ;
		}
		rra(stack_a);
		len--;
	}
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
