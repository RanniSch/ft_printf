/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:58:28 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 23:10:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/* converts int into (small letters)
    hexa -> 0123456789abcdef */

int	ft_hexadecimal_small(unsigned int hds)
{
	unsigned long	quo;
	int				i;
	int				temp;
	int				length;
	char			hexa_num[100];

	//printf("\n%d\n", hds);
	/*if (hds == 0)
		hexa_num[0] = '0';*/
	if (hds == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	/*if (ptr_yes == 1)
		ft_putstr_fd("0x", 1);*/
	i = 1;
	quo = hds;
	while (quo != 0)
	{
		temp = quo % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55 + 32;
		hexa_num[i] = temp;
		quo = quo / 16;
		i++;							// ggf. i als Länge nehmen und returnen und print_hexa void machen.
	}
	hexa_num[i] = '\0';
	length = ft_print_hexa(&hexa_num[i], i);
	return (length);
}

/*int	main(void)
{
	int length;

	length = ft_hexadecimal_small(15, 0);
	printf("\n%d\n", length);
	return (0);
}*/
