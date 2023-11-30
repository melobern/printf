/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:01:27 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/30 11:29:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "header/ft_printf.h"

int	main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	unsigned int uns = 4294967295;
	char	*str = "Hello, is it me you're looking for ?";
	char *deci = "deci";
	unsigned nosi = 522;
	float  flot= 5.5;
	long lofi = 5;
	int five = 5;
	char car = '5';
	char* st2 = "55";
	char* st3 = "55";
	char* st4 = "55";
/*
	printf("YOURS : %i\n", ft_printf("A char to bless your heart : %c\tA int to count on : %i\tAn other : %i\tAn unsigned anonymous: %u\n%s\nA percent to make you lucky %%\nA.. x ? %x\tA.. X ?%X\n",
							 'c',
								INT_MIN,
								INT_MAX,
								uns,
								str,
								uns,
								uns));
	printf("MINE : %i\n", printf("A char to bless your heart : %c\tA int to count on : %i\tAn other : %i\tAn unsigned anonymous: %u\n%s\nA percent to make you lucky %%\nA.. x ? %x\tA.. X ?%X\n",
							 'c',
								INT_MIN,
								INT_MAX,
								uns,
								str,
								uns,
								uns));



	printf("YOURS :%i\n", ft_printf("A beautiful pointer :%p\nTen others :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n", &deci,
												&str,
												&uns,
												&nosi,
												&flot,
												&lofi,
												&five,
												&car,
												&st2,
												&st3,
												&st4));
	printf("MINE : %i\n", printf("A beautiful pointer :%p\nTen others :\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n", &deci,
												&str,
												&uns,
												&nosi,
												&flot,
												&lofi,
												&five,
												&car,
												&st2,
												&st3,
												&st4));
	printf("YOURS :%i\n", ft_printf(" NULL %s NULL ", NULL));
	printf("MINE :%i\n", printf(" NULL %s NULL ", NULL));


        printf("YOURS : %i\n", ft_printf(" %d ", 0));
        printf("YOURS : %i\n", ft_printf(" %d ", INT_MAX));
        printf("YOURS : %i\n", ft_printf(" %d ", INT_MIN));
        printf("YOURS : %i\n", ft_printf(" %d ", LONG_MAX));
        printf("YOURS : %i\n", ft_printf(" %d ", LONG_MIN));
        printf("YOURS : %i\n", ft_printf(" %d ", UINT_MAX));
        printf("YOURS : %i\n", ft_printf(" %d ", ULONG_MAX));
        printf("YOURS : %i\n", ft_printf(" %d ", 9223372036854775807LL));
        printf("YOURS : %i\n", ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
        printf("MINE : %i\n", printf(" %d ", 0));
        printf("MINE : %i\n", printf(" %d ", INT_MIN));
        printf("MINE : %i\n", printf(" %d ", LONG_MAX));
        printf("MINE : %i\n", printf(" %d ", LONG_MIN));
        printf("MINE : %i\n", printf(" %d ", UINT_MAX));
        printf("MINE : %i\n", printf(" %d ", ULONG_MAX));
        printf("MINE : %i\n", printf(" %d ", 9223372036854775807LL));
        printf("MINE : %i\n", printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
      
	printf("PRINTF :%i\n", printf(" %p ", -1));
	printf("YOURS :%i\n", ft_printf(" %p ", -1));
        printf("PRINTF :%i\n", printf(" %p ", 1));
        printf("YOURS :%i\n", ft_printf(" %p ", 1));
        printf("PRINTF :%i\n", printf(" %p ", 15));
        printf("YOURS :%i\n", ft_printf(" %p ", 15));
        printf("PRINTF :%i\n", printf(" %p ", 16));
        printf("YOURS :%i\n", ft_printf(" %p ", 16));
        printf("PRINTF :%i\n", printf(" %p ", 17));
        printf("YOURS :%i\n", ft_printf(" %p ", 17));
        printf("PRINTF :%i\n", printf(" %p %p ", INT_MIN, INT_MAX));
        printf("YOURS :%i\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
        printf("PRINTF LONG_MIN :%i\n", printf(" %p ", LONG_MIN));
        printf("YOURS LONG_MIN :%i\n", ft_printf(" %p ", LONG_MIN));
        printf("PRINTF LONG_MAX :%i\n", printf(" %p ", LONG_MAX));
        printf("YOURS  LONG_MAX :%i\n", ft_printf(" %p ", LONG_MAX));
        printf("PRINTF LONG_MIN, LONG_MAX :%i\n", printf(" %p %p ", LONG_MIN, LONG_MAX));
        printf("YOURS LONG_MIN, LONG_MAX :%i\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
        printf("PRINTF ULONG_MAX, -ULONG_MAX :%i\n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
        printf("YOURS ULONG_MAX, -ULONG_MAX :%i\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
        printf("PRINTF :%i\n", printf(" %p %p ", 0, 0));
*/	
        printf("YOURS :%i\n", ft_printf(" %p %p ", 0, 0));
        printf("YOURS :%i\n", ft_printf(" blop %"));
	return (0);
}
