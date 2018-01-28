/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:13:24 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/23 17:13:04 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_count(int n, int *count)
{
	while (n /= 10)
		*count = *count * 10;
}

void		ft_putnbr_fd(int n, int fd)
{
	int	count;

	if (!fd)
		return ;
	count = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_count(n, &count);
	while (count / 10)
	{
		ft_putchar_fd(((n / count) + '0'), fd);
		n %= count;
		count /= 10;
	}
	ft_putchar_fd((n + '0'), fd);
}
