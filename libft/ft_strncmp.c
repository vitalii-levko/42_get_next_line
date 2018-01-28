/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:03:16 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/22 13:07:07 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n > 0)
	{
		while (*str1 == *str2 && n-- > 0)
		{
			str1++;
			str2++;
			if ((*str1 == '\0' && *str2 == '\0') || n == 0)
				return (0);
		}
		return (*str1 - *str2);
	}
	return (0);
}
