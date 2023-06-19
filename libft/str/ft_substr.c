/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:29:14 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:18 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	size_t			size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (len > size)
		len = size;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < size && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
