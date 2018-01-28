/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:16:54 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:29:50 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*curr;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	curr = f(lst);
	if (!(map = ft_lstnew(curr->content, curr->content_size)))
		return (NULL);
	head = map;
	while ((lst = lst->next))
	{
		curr = f(lst);
		if (!(map->next = ft_lstnew(curr->content, curr->content_size)))
		{
			ft_lstfree(head);
			return (NULL);
		}
		map = map->next;
	}
	return (head);
}
