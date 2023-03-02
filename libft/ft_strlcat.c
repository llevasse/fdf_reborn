/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:51:42 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/23 08:36:06 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	char_left;
	unsigned int	dst_len;
	unsigned int	i;

	if (size == 0 || size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	dst_len = ft_strlen(dst);
	char_left = size - dst_len;
	if (char_left == 0)
		return (dst_len + ft_strlen(src));
	while (src[i] && char_left > 1)
	{
		dst[dst_len + i] = src[i];
		char_left--;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
