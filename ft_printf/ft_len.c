/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:50:32 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/29 14:00:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_int_len(int n)
{
	int	len;

	len = 0;
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

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_hex_len(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex != 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}
