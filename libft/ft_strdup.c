/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:29:15 by esozbalt          #+#    #+#             */
/*   Updated: 2024/06/02 18:32:14 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	s = (char *)malloc(len * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, str, len);
	s[len] = '\0';
	return (s);
}
