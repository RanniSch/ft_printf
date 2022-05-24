/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:12:37 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:40:40 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* This function converts pointer to int, so that the
    next function can work with the int. */

int	ft_ptrtoint(void *pt)
{
	unsigned long	hex_pt;

	hex_pt = (unsigned long)pt;
	ft_putstr_fd("0x", 1);
	return (2 + ft_hexadecimal_pointer(hex_pt));
}
