/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:54:11 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:37:14 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstsize(t_list *head)
{
	t_list	*lst;
	size_t	size;

	if (!head)
		return (0);
	size = 0;
	lst = head;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
