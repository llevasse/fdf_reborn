/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:08:31 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:15 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**free_tab(char **tab, int index_word)
{
	int	i;

	i = 0;
	while (i < index_word)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**alloc_tab(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	res = malloc((j + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

char	*get_word(char const *s, char c, int i)
{
	int		j;
	int		len_word;
	char	*res;

	j = 0;
	len_word = 0;
	while (s[i + len_word] != c && s[i + len_word] != '\0')
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

int	skip_char(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		index_word;

	if (!s)
		return (NULL);
	index_word = 0;
	res = alloc_tab(s, c);
	if (!res)
		return (NULL);
	i = skip_char(s, c, 0);
	while (s[i] != '\0')
	{
		res[index_word] = get_word(s, c, i);
		if (!res[index_word])
			return (free_tab(res, index_word));
		while (s[i] != c && s[i] != '\0')
			i++;
		i = skip_char(s, c, i);
		index_word++;
	}
	res[index_word] = NULL;
	return (res);
}

/* #include <stdio.h>
#include <malloc/malloc.h>
int main()
{
	char **tab;
	unsigned long sizetab;

	void * p2 = malloc(sizeof(char *) * 2);
	tab = ft_split("chinimala", ' ');
	sizetab = sizeof(tab);
	printf("size tab : %lu\n", malloc_size(tab));
	printf("expected size : %lu\nTAB :\n", malloc_size(p2));
	int i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n",tab[i]);
		i++;
	}
	printf("%s\n",tab[i]);
} */