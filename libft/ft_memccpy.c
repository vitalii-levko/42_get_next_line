/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:48:39 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:57:09 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, \
		size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (i < n)
	{
		*s2 = *s1;
		if (*s1 == (unsigned char)c)
			return ((void *)++s2);
		s1++;
		s2++;
		i++;
	}
	return (NULL);
}
