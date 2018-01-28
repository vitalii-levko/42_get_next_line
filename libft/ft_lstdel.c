/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:15:26 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:25:56 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		lst = *alst;
		*alst = (*alst)->next;
		del((lst->content), lst->content_size);
		free(lst);
		lst = NULL;
	}
}
