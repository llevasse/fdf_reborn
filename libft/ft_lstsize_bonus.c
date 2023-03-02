/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:41:40 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/21 10:09:22 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	return (0);
}
