/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:24:08 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 18:28:38 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	while ((*str != '\0') && (*str != (char)c))
		str++;
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (NULL);
}
