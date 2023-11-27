/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:01:27 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/27 20:51:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "headers/ft_printf.h"

int	main(void)
{
	printf("YOURS : %i\n", ft_printf("A char to bless your heart : %c\n", 'c'));
	printf("MINE : %i\n", printf("A char to bless your heart : %c\n", 'c'));

	int num = 42;
	printf("YOURS : %i\n", ft_printf("A int to count on you : %i\n", num));
	printf("MINE : %i\n", printf("A int to count on you : %i\n", num));
	printf("YOURS : %i\n", ft_printf("A int to count on you : %i\n", INT_MIN));
	printf("MINE : %i\n", printf("A int to count on you : %i\n", INT_MIN));
	printf("YOURS : %i\n", ft_printf("A int to count on you : %i\n", INT_MAX));
	printf("MINE : %i\n", printf("A int to count on you : %i\n", INT_MAX));
	
	unsigned int uns = 4294967295;
	printf("YOURS : %i\n", ft_printf("Unsigned anonymous : %u\n", uns));
	printf("MINE : %i\n", printf("Unsigned anonymous : %u\n", uns));

	char	*str = "Hello, is it me you're looking for ?";
	printf("YOURS : %i\n", ft_printf("%s\n", str));
	printf("MINE : %i\n", printf("%s\n", str));
	

	printf("YOURS : %i\n", ft_printf("A percent to make you lucky : %%\n"));
	printf("MINE : %i\n", printf("A percent to make you lucky : %%\n"));
	
	return (0);
}
