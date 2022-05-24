/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:59:17 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:38:51 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* if *pt = 0; 8xNull is produced. */

int	ft_hexadecimal_pointer(unsigned long hex_pt)
{
	int	length;

	length = 1;
	if (hex_pt >= 16)
		ft_hexadecimal_pointer(hex_pt / 16);
	ft_print_pointer(hex_pt % 16);
	while (hex_pt >= 16)
	{
		hex_pt = hex_pt / 16;
		length++;
	}
	return (length);
}
