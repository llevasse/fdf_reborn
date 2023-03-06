/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:08:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/03/06 10:43:00 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (NULL);
}
	
char	**alloc_tab(char const *s, char *skip)
{
	int		i;
	int		j;
	char	**res;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (ft_is_in_str(skip, s[i]) && s[i] != '\0')
			i++;
		if (!ft_is_in_str(skip, s[i]) && s[i] != '\0')
			j++;
		while (!ft_is_in_str(skip, s[i]) && s[i] != '\0')
			i++;
	}
	res = malloc((j + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

char	*get_word(char const *s, char *skip, int i)
{
	int		j;
	int		len_word;
	char	*res;

	j = 0;
	len_word = 0;
	while (!ft_is_in_str(skip, s[i + len_word]) && s[i + len_word] != '\0')
		len_word++;
	res = malloc((len_word + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (j < len_word && s[i] != '\0')
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

int	skip_char(const char *s, char *skip, int i)
{
	while (ft_is_in_str(skip, s[i]) && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char *skip)
{
	char	**res;
	int		i;
	int		index_word;

	if (!s)
		return (NULL);
	index_word = 0;
	res = alloc_tab(s, skip);
	if (!res)
		return (NULL);
	i = skip_char(s, skip, 0);
	while (s[i] != '\0')
	{
		res[index_word] = get_word(s, skip, i);
		if (!res[index_word])
			return (free_tab(res));
		while (!ft_is_in_str(skip, s[i]) && s[i] != '\0')
			i++;
		i = skip_char(s, skip, i);
		index_word++;
	}
	res[index_word] = NULL;
	return (res);
}
