/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:58:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/02/10 16:12:49 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_nl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	fill_char(char *dst, char *src, int till_nl)
{
	int	i;

	i = 0;
	if (!src)
		dst[0] = '\0';
	else if (!till_nl)
	{
		while (src[i] > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (src[i] > 0 && src[i] != '\n')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = src[i];
		dst[i + 1] = 0;
	}
}
