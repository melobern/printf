/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:57:34 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/27 11:40:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char * format, ...);

#endif
