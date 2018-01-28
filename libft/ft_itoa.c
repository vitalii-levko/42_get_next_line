/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:10:52 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/21 15:39:14 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_itoaifneg(int *n, int *count, int *i, char *str)
{
	if (*n < 0)
	{
		if (*n == -2147483648)
		{
			str[0] = '-';
			str[1] = '2';
			*n = 147483648;
			*count = *count / 10;
			*i = 2;
		}
		else
		{
			str[0] = '-';
			*i = 1;
			*n = -*n;
		}
	}
	else
		*i = 0;
}

static void	ft_itoacount(int *n, int *count, int *i)
{
	if (*n < 0)
		*n = -*n;
	while (*n / 10)
	{
		*count = *count * 10;
		*i = *i + 1;
		*n = *n / 10;
	}
}

char		*ft_itoa(int n)
{
	int		count;
	int		tmp;
	char	*str;
	int		i;

	count = 1;
	i = 1;
	tmp = n;
	if (n < 0)
		i++;
	ft_itoacount(&n, &count, &i);
	if (!(str = ft_strnew(i)))
		return (NULL);
	ft_itoaifneg(&tmp, &count, &i, str);
	while (count / 10)
	{
		str[i] = (tmp / count) + '0';
		tmp = tmp % count;
		count = count / 10;
		i++;
	}
	str[i] = tmp + '0';
	return (str);
}
