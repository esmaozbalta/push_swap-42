/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:59:59 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 16:13:11 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		nb = (nb * 10) + (str[i++] - '0');
	if ((nb > 2147483647 && sign == 1) || (nb > 2147483647 && sign == -1))
	{
		write (2, "Error\n", 6);
		exit (0);	
	}
	if ((str[i] && !ft_isdigit(str[i]) && str[i] != 10)
		|| (str[i] == '-' && !str[1]))
	{
		write (2, "Error\n", 6);
		exit (0);
	}
	return ((int)(sign * nb));
}
