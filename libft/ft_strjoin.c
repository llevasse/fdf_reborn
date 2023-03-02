/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 06:53:53 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/13 16:17:10 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_str(char *s1, char *s2);

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	joined = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!joined)
		return (free(s1), NULL);
	while (s1[i] != '\0')
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (free(s1), joined);
}

int	fill_str(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	return (i);
}
