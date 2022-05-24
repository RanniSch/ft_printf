/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:58:28 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:38:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* converts int into hexa -> 0123456789abcdef 
	base-16 number system. */

int	ft_hexadecimal(unsigned int hd, char c)
{
	int	length;

	length = 1;
	if (hd >= 16)
		ft_hexadecimal(hd / 16, c);
	ft_print_hexa(hd % 16, c);
	while (hd >= 16)
	{
		hd = hd / 16;
		length++;
	}
	return (length);
}
