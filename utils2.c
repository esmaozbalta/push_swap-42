/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:23:31 by esozbalt          #+#    #+#             */
/*   Updated: 2024/05/17 18:42:02 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dst)//src den dst e eleman taşır
{
	t_stack *tmp;

	if (ft_lstsize(*src) == 0) //src boşsa return
		return ;
	tmp = *src; //tmp artık src nin değerini işaret eder
	*src = (*src)->next; // src artık bir sonraki elemanın değerini işaret eder yani değerler geri kaymış olur
	ft_lstadd_front(dst,tmp);
}

void	pa(t_stack **dst_a, t_stack **src_b)
{
	push(src_b, dst_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **dst_b, t_stack **src_a)
{
	push(src_a, dst_b);
	write(1, "pa\n", 3);
}

