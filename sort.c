/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:57:03 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 20:17:00 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selectsort(t_stack **a_stack, t_stack **b_stack, int len)
{
	if (len == 2)
		sa(a_stack);//ilk iki elemanin yerini degisir
	if (len == 3)
		sort_3(a_stack);
	if (len == 4)
		sort_4(a_stack, b_stack);
	if (len == 5)
		sort_5(a_stack, b_stack);
	if (len > 5)
		radixbin(a_stack, b_stack);
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

void	sort_3(t_stack **a_stack)
{
	index_setter(a_stack);
	if ((*a_stack)->index == 2)
		ra(a_stack);//ilk elemani sona tasir
	else if ((*a_stack)->next->index == 2)
		rra(a_stack);//son elemani basa tasir
	if (!check_sorted(a_stack))
		sa(a_stack);
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
