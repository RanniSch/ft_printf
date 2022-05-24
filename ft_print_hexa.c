/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:07:22 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:39:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* prints hexa (reverse printing) for %x, %X and %p. 
	Cannot be greater than 16 (f) as we have base 16. */

void	ft_print_hexa(unsigned int hd, char c)
{
	if (hd < 10)
		ft_putchar_fd(hd + '0', 1);
	else if (c == 'x')
		ft_putchar_fd('a' + hd - 10, 1);
	else if (c == 'X')
		ft_putchar_fd('A' + hd - 10, 1);
}
