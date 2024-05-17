/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:24:18 by esozbalt          #+#    #+#             */
/*   Updated: 2024/05/17 19:08:47 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack) //en üstteki iki elemanın yerini değiştirme (bardak boşaltma mantığı)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack) < 2) //stackin boyutu 2 den küçük ise 0 veya 1 eleman vardır değişecek birşey yoktur
		return;
	tmp =  (*stack)->next; //stackin şuan işaret ettiği elemanın bir sonrakinin adresini tmp ye atar
	(*stack)->next = tmp->next;//tmpdeki ikinci elemanın adresi stack de ki ikinci elemana atılır (*stack->next artık tmp->next i işaret eder onun değerini alır)
	tmp->next = *stack; //tmpnin ikinci elemanına stackin elemanı adresi atılır
	*stack = tmp; //tmp (stackin ikinci elemanı) stack e atılır
}

void	sa(t_stack **a_stack)//a_stack in en üst iki elemanını değiştir
{
	swap(a_stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b_stack)//b_stack in en üst iki elemanını değiştir
{
	swap(b_stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a_stack, t_stack **b_stack) //ss fonksiyonu, hem a_stack hem de b_stack yığınlarının en üstündeki iki elemanı değiştirir
{
	if ((ft_lstsize(*a_stack) < 2) || (ft_lstsize(*b_stack) < 2))//neden ||
		return ;
	swap(a_stack);
	swap(b_stack);
	write(1, "ss\n", 3);
}
