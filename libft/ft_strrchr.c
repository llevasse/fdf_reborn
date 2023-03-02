/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:52:48 by llevasse          #+#    #+#             */
/*   Updated: 2022/12/09 09:42:04 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last_occ;

	last_occ = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			last_occ = i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	if (last_occ != -1)
		return ((char *)s + last_occ);
	return (NULL);
}
