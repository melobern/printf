/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:07 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/29 17:24:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int n)
{
	int	len;

	len = ft_int_len(n);
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < 10)
			ft_putchar(n + '0');
		if (n >= 10)
		{
			ft_put_int(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
	return (len);
}

int	ft_put_uns(unsigned int n)
{
	int	len;

	len = ft_unsigned_len(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n >= 10)
	{
		ft_put_uns(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (len);
}
