/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:59:17 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 23:33:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal_pointer(void *pt)
{
	unsigned long	quo;
	int				i;
	int				temp;
	int				length;
    char			hexa_num[100];
    unsigned long	hex_address;
    
    hex_address = (unsigned long)pt;
	//printf("\n%d\n", hds);
	/*if (hds == 0)
		hexa_num[0] = '0';*/
	if (hex_address == 0)   // für *pt = 0 werden 8 Nullen erzeugt!!!
	{
		ft_putnbr_fd(0, 1);
		return (8);
	}
	i = 1;
	quo = hex_address;
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
	length = ft_print_pointer(&hexa_num[i], i);
	return (length);
}
