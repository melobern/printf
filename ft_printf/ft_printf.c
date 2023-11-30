/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:48 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/30 13:15:43 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_format(char c, char *charset)
{
	int	x;

	x = 0;
	while (charset[x])
	{
		if (c == charset[x])
			return (1);
		x++;
	}
	return (0);
}

static int	ft_count_args(const char *str)
{
	int	num;
	int	c;

	num = 0;
	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		if (str[c + 1])
		{
			if (str[c] == '%' && ft_is_format(str[c + 1], "cspdiuxX%"))
			{
				num++;
				c++;
			}
		}
		c++;
	}
	return (num);
}

static int	ft_chose_print(const char c, va_list args)
{
	if (c == 'c')
	{
		ft_putchar(va_arg(args, int));
		return (1);
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_put_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_put_uns(va_arg(args, unsigned int)));
	else if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (c == 'p')
		return (ft_put_ptr(va_arg(args, unsigned long int)));
	else if (c == 'x' || c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;
	int		args_num;
	int		cursor;

	if (write(1, 0, 0) == -1)
		return (0);
	if (str == NULL)
		return (-1);
	args_num = ft_count_args(str);
	print_len = ft_strlen(str) - (args_num * 2);
	va_start(args, str);
	cursor = 0;
	while (str[cursor])
	{
		if (str[cursor] != '%')
			ft_putchar(str[cursor]);
		else if (str[cursor + 1])
			print_len += ft_chose_print(str[++cursor], args);
		else
			print_len = -1;
		cursor++;
	}
	va_end(args);
	return (print_len);
}
