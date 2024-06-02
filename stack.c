/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:07:52 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 21:47:35 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//argümanını boşluklara göre ayırarak 
//her bir parçayı birer düğüm olarak bağlı listeye ekler ve 
//daha sonra dinamik olarak ayrılan belleği serbest bırakır.
void	split_node(t_stack **a_stack, char *av)
{
	int		i;
	char	**splitted;
	t_stack	*node; 

	i = 0;
	splitted = ft_split(av, ' '); //girilen argumani bosluklardan ayirir 
	while(splitted[i])
	{
		node = ft_lstnew(ft_atoi(splitted[i]));//parcalari int e cevirir ve t_stack dugumu olusturup node a atar
		ft_lstadd_back(a_stack, node);//a_stack e node lari ekler
		i++;
	}
	i = 0;
	while(splitted[i])//isimiz bitti her elemani node a atadik
		free(splitted[i++]);//dizinin her elemani serbest birakilr
	free(splitted);//dizinin kendisi serbest birakilir
}

void	create_stack(t_stack **a_stack, char **av)
{
	t_stack	*node;
	int	i;

	i = 1; //av[0] programin adi
	while (av[i])
	{
		if (ft_strrchr(av[i],' ') != NULL) //icinde bosluk var ise
		{
			space_check(av[i]); //argumanda sadece space var mi diye kontrol eder
			split_node(a_stack, av[i]);
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

int	check_sorted(t_stack **a_stack)
{
	t_stack	*tmp;
	int		i;
	int		len;

	len = lenstack(a_stack);
	i = 0;
	tmp = *a_stack; //tmp ye ilk eleman atilir
	while (tmp->next)//son dugume kadar dolasir
	{
		if ((tmp->value) < (tmp->next->value))//Geçerli düğümün verisi bir sonraki düğümün verisinden küçükse sayaç artırılır.
			i++;
		tmp = tmp->next;//tmp bir sonraki dugume gecer
	}
	if (i == (len - 1))//tum elemanlar artan siradadir
		return (1);
	return (0);
}

void	set_neg(t_stack **a_stack)//gösterilen bağlı listedeki her düğümün index değerini -1 olarak ayarlar. 
{
	t_stack	*tmp;

	tmp = *a_stack;
	while (tmp)//tum tmpyi dolasir tum que degerlerini -1 yapar
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

int	lenstack(t_stack **a_stack)
{
	t_stack	*tmp;
	int		len;

	tmp = *a_stack; //tmp->next NULL oldugunda leni arttiramadigindan 1 den baslar
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
