/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:51:15 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:54:21 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*str1;
	char		*str2;

	if (!dst && !src)
		return (NULL);
	str1 = (char *)src;
	str2 = (char *)dst;
	if (str1 < str2)
	{
		str1 = str1 + len - 1;
		str2 = str2 + len - 1;
		while (len-- != 0)
			*str2-- = *str1--;
	}
	else
		while (len-- != 0)
			*str2++ = *str1++;
	return ((void *)dst);
}
