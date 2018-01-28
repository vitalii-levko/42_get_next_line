/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:26:37 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:52:59 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s1;
	char	*s2;

	if (!dst && !src)
		return (NULL);
	s1 = (char*)src;
	s2 = (char*)dst;
	while (n-- > 0)
		s2[n] = s1[n];
	return (dst);
}
