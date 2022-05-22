/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:58:28 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/22 19:39:17 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* converts int into (small letters)
    hexa -> 0123456789abcdef */

int	ft_hexadecimal_small(unsigned long hds, int ptr_yes)
{
	unsigned long	quo;
	int				i;
	int				temp;
	int				length;
	char			hexa_num[100];

	if (ptr_yes == 1)
		ft_putstr_fd("0x", 1);
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
		i++;
	}
	hexa_num[i] = '\0';
	length = ft_print_hexa(&hexa_num[i], i);
	return (length);
}
