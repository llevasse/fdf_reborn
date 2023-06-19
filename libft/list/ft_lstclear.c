/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llevasse <llevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:56:13 by llevasse          #+#    #+#             */
/*   Updated: 2023/05/25 14:50:11 by llevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_last(t_list *lst);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		while ((*lst)->next != NULL)
		{
			del((*lst)->content);
			*lst = (*lst)->next;
		}
		del((*lst)->content);
		while (temp->next != NULL)
			free_last(temp);
		free(temp);
	}
	*lst = NULL;
	return ;
}

void	free_last(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
