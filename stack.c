/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:07:52 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/13 19:38:43 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_node(t_stack **stack_a, char *av)
{
	int		i;
	char	**splitted;
	t_stack	*node;

	i = 0;
	splitted = ft_split(av, ' ');
	while (splitted[i])
	{
		node = ft_lstnew(ft_atoi(splitted[i]));
		ft_lstadd_back(stack_a, node);
		i++;
	}
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	create_stack(t_stack **stack_a, char **av)
{
	t_stack	*node;
	int		i;

	i = 1;
	while (av[i])
	{
		if (ft_strrchr(av[i], ' ') != NULL)
		{
			space_check(av[i]);
			split_node(stack_a, av[i]);
		}
		else
		{
			node = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(stack_a, node);
		}
		i++;
	}
	catch_error(stack_a);
}

int	check_sorted(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;
	int		len;

	len = lenstack(stack_a);
	i = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == (len - 1))
		return (1);
	return (0);
}

void	set_neg(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

int	lenstack(t_stack **stack_a)
{
	t_stack	*tmp;
	int		len;

	tmp = *stack_a;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
