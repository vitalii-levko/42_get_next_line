/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:09:04 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 16:28:59 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_nextiter(size_t *len, size_t *i)
{
	*len = *len + 1;
	*i = *i + 1;
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	tmp;
	size_t	start;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	while (s[i] != '\0')
	{
		tmp = i;
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
		if (tmp != i && s[i] != '\0')
			len += i - tmp;
		else if (s[i] == '\0')
			break ;
		ft_nextiter(&len, &i);
	}
	return (ft_strsub(s, start, len));
}
