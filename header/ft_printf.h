/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:57:34 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/29 17:35:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_int_len(int n);
int		ft_unsigned_len(unsigned int n);
int		ft_hex_len(unsigned int hex);
int		ft_putstr(char *s);
int		ft_put_int(int n);
int		ft_put_uns(unsigned int n);
int		ft_put_ptr(unsigned long int p);
int		ft_put_hex(unsigned int hex, char format);
int		ft_strlen(const char *s);
void	ft_putchar(char c);

#endif
