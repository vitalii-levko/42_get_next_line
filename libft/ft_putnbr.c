/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:11:39 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/22 16:22:39 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	int	tmp;
	int	count;

	count = 1;
	if (n == -2147483648)
	{
		ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	tmp = n;
	while (n /= 10)
		count *= 10;
	while (count / 10)
	{
		ft_putchar((tmp / count) + '0');
		tmp %= count;
		count /= 10;
	}
	ft_putchar(tmp + '0');
}
