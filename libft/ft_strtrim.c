/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:41:07 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/23 10:39:25 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_start_after_trim(char const *s1, char const *set);
int		get_end_after_trim(char const *s1, char const *set);
int		check_set(char c, char const *set);
char	*malloc_char(char *res, int end, int start);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = get_start_after_trim(s1, set);
	end = get_end_after_trim(s1, set);
	res = NULL;
	res = malloc_char(res, end, start);
	i = 0;
	if (!res)
		return (NULL);
	if (end > 0)
	{
		while (start + i <= end)
		{
			res[i] = s1[start + i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

char	*malloc_char(char *res, int end, int start)
{
	if (end > 0)
		res = malloc((end - start) * sizeof(char) + 2);
	else
		res = malloc(sizeof(char));
	return (res);
}

int	get_start_after_trim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (check_set(s1[i], set) == 1)
		i++;
	return (i);
}

int	get_end_after_trim(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (check_set(s1[i], set) == 1 && i > 0)
		i--;
	return (i);
}

int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
