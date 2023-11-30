/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:06:12 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/29 17:27:53 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(unsigned int hex, char format)
{
	if (hex >= 16)
	{
		ft_print_hex(hex / 16, format);
		ft_print_hex(hex % 16, format);
	}
	else
	{
		if (hex < 10)
			ft_putchar(hex + '0');
		else
		{
			if (format == 'x')
				ft_putchar(hex - 10 + 'a');
			else if (format == 'X')
				ft_putchar(hex - 10 + 'A');
		}
	}
}

int	ft_put_hex(unsigned int hex, char format)
{
	if (hex == 0)
		write(1, "0", 1);
	else
		ft_print_hex(hex, format);
	return (ft_hex_len(hex));
}

static void	ft_print_ptr(unsigned long int ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16, len);
		ft_print_ptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
		{
			ft_putchar(ptr + '0');
			*len += 1;
		}
		else
		{
			ft_putchar(ptr - 10 + 'a');
			*len += 1;
		}
	}
}

int	ft_put_ptr(unsigned long int ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	ft_print_ptr(ptr, &len);
	return (len);
}
