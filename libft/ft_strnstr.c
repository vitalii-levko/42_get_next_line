/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:27:31 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/22 14:21:51 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	newlen;

	if (*needle == '\0')
		return ((char *)haystack);
	newlen = len - ft_strlen(needle);
	while (*haystack != '\0' && newlen-- >= 0)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, \
			ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
