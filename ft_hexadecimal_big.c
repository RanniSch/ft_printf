/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:54:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/21 22:28:48 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/* converts int into 
    hexa -> 0123456789ABCDEF */

void	ft_hexadecimal_big(unsigned int hd)
{
	long int	quo;
	int			i;
	int			temp;
	char		hexa_num[100];
	char		result[100];

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
	ft_print_hexa(&hexa_num[i], i);
}
