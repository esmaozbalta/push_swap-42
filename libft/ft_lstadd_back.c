/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:20:53 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 16:24:43 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (!lst)
	{
		return ;
	}
	if (*lst)
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
