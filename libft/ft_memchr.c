/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:48:46 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/11 14:43:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*haystack;
	unsigned char	to_find;

	haystack = (unsigned char *)s;
	to_find = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (haystack[i] == to_find)
			return (haystack + i);
		i++;
	}
	return (NULL);
}
