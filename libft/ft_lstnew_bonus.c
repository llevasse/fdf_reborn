/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:07:45 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/15 10:01:11 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*new_el;

	new_el = malloc(sizeof(struct s_list));
	if (!new_el)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
