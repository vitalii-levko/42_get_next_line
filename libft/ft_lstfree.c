/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:14:09 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:36:09 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return ;
	while (lst)
	{
		curr = lst;
		lst = lst->next;
		free(curr);
		curr = NULL;
	}
}
