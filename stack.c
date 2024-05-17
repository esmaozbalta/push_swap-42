/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:07:52 by esozbalt          #+#    #+#             */
/*   Updated: 2024/05/17 20:15:15 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **a_stack, char **av)
{
	t_stack	*node;
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strrchr(av[i],' ') != NULL)
		{
			space_check(av[i]);
			split_nodes(a_stack, av[i]);
		}
		else
		{
			node = ft_lstnew(ft_atoi(av[i]));
			ft_lstadd_back(a_stack, node);
		}
		i++;
	}
	catch_error(a_stack);
}