/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:48 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/27 20:46:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cspdiuxX%
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
malloc, free, write,
va_start, va_arg, va_copy, va_end
*/
#include "ft_printf.h"
#include "libft.h"
static int	ft_args_nums(const char *str)
{
	int	num;
	int	c;

	num = 0;
	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		if (str[c] == '%')
			num++;
		c++;
	}
	return (num);
}

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= -2000000000)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_put_int(int n, int fd)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
		if (n >= 10)
		{
			ft_put_int(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
	}
	return (ft_num_len(n));
}

unsigned ft_put_uns(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	if (n >= 10)
	{
		ft_put_uns(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (ft_num_len(n));
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		write(1, &(s[len]), 1);
		len++;
	}
	return (len);
}

/*
cspdiuxX%
-------------------------------------------------------------• %c Prints a single character.
-------------------------------------------------------------• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
-------------------------------------------------------------• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
-------------------------------------------------------------• %% Prints a percent sign.
malloc, free, write,
va_start, va_arg, va_copy, va_end
*/
static	int ft_chose_print(const char c, va_list args, int print_len)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'i')
		return (ft_put_int(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_put_uns(va_arg(args, int), 1));
	else if(c == '%')
	{
		ft_putchar_fd('%', 1);
		return (3);
	}
	return (print_len);	
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	print_len;
	int	args_num;
	int	cursor;

	args_num = ft_args_nums(str);
	print_len = (int)ft_strlen(str) - (args_num * 2);
	va_start(args, str);
	cursor = 0;
	while (str[cursor])
	{
		if (str[cursor] != '%')
			ft_putchar_fd(str[cursor], 1);
		else
		{
			print_len += ft_chose_print(str[cursor + 1], args, print_len);
			cursor ++;
		}
		cursor++;
	}
	va_end(args);
	return (print_len);
}
