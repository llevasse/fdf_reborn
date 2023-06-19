/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:17:21 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:17 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			size;

	if (!needle && !haystack)
		return (NULL);
	i = 0;
	size = ft_strlen(needle);
	if (needle[i] == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, size) == 0 && i + size <= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
