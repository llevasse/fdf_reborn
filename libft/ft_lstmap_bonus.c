/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:20:22 by llevasse          #+#    #+#             */
/*   Updated: 2022/11/21 17:13:19 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	temp = lst;
	while (lst->next != NULL)
	{
		ft_lstadd_back(&new_list, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	ft_lstadd_back(&new_list, ft_lstnew(f(lst->content)));
	temp = lst;
	while (lst->next != NULL)
	{
		temp = lst->next;
		del(lst->content);
		free(lst);
		lst = temp;
	}
	return (new_list);
}
