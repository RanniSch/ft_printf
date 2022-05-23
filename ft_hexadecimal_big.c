/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:54:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 22:35:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* converts int into 
    hexa -> 0123456789ABCDEF */

int	ft_hexadecimal_big(unsigned int hd)
{
	long int	quo;
	int			i;
	int			temp;
	int			length;
	char		hexa_num[100];

	if (hd == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}		
	i = 1;
	quo = hd;
	while (quo != 0)
	{
		temp = quo % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexa_num[i] = temp;
		quo = quo / 16;
		i++;
	}
	hexa_num[i] = '\0';
	length = ft_print_hexa(&hexa_num[i], i);
	return (length);
}
