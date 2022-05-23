/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:28:55 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 14:55:04 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_print_int(int n)
{
    int length;

    if (n == -2147483648)
	{
		ft_putnbr_fd(n, 1);
		return (11);
	}
    length = ft_int_length(n);
    ft_putnbr_fd(n, 1);
    return (length);
}
