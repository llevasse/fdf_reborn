/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb2unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 13:53:04 by llevasse          #+#    #+#             */
/*   Updated: 2023/06/11 10:56:34 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_nb2unicode(unsigned int nb)
{
	char	*res;
	char	*base;
	char	*temp;
	int		i;

	base = "0123456789ABCDEF";
	res = malloc(9 * sizeof(char));
	if (!res)
		return (NULL);
	ft_memset(res, '0', 8);
	res[8] = 0;
	i = 0;
	while (nb > 0)
	{
		res[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	ft_str_revert(res);
	temp = ft_strjoin("\\U", res);
	return (temp);
}
