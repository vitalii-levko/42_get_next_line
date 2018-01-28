/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:03:38 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/22 15:48:09 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dsize;
	size_t		dlen;

	d = dst;
	s = src;
	dsize = size;
	while (dsize-- > 0 && *d != '\0')
		d++;
	dlen = d - dst;
	dsize = size - dlen;
	if (dsize == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (dsize != 1)
		{
			*d++ = *s;
			dsize--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
