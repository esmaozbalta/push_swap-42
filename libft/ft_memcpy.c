/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:46:32 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 16:49:30 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	size_t	i;

	if (src == dst || size == 0)
		return (dst);
	i = 0;
	while (i < size)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
