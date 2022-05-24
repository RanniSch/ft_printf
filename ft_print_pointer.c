/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:02:26 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:39:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(unsigned long hex_pt)
{
	if (hex_pt < 10)
		ft_putchar_fd(hex_pt + '0', 1);
	else
		ft_putchar_fd('a' + hex_pt - 10, 1);
}
