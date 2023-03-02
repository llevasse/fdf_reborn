/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:46:14 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/23 08:35:57 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	replace;

	replace = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = replace;
		i++;
	}
	return (b);
}
