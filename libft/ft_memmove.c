/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:48:19 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/17 08:55:56 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if ((dest || src) && n > 0)
	{	
		if ((unsigned char *)src > (unsigned char *)dest)
		{
			while (i < n)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
				i++;
			}
		}
		else
		{
			while (i < n)
			{
				((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
				n--;
			}
		}
	}
	return (dest);
}
