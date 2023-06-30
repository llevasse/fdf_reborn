/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:08:29 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/30 10:35:10 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	get_nb_word(const char *str, char *to_skip)
{
	int	i;
	int	nbr;

	i = skip_char(str, to_skip, 0);
	if (!str[i])
		return (0);
	nbr = 1;
	while (str[i])
	{
		if (ft_is_in_str(to_skip, str[i]))
		{
			i = skip_char(str, to_skip, i);
			if (str[i] && !ft_is_in_str(to_skip, str[i]))
				nbr++;
			else
				break ;
		}
		i++;
	}
	return (nbr);
}
