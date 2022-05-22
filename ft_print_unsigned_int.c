/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:24:38 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/22 22:17:38 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_unsigned_int(unsigned int n)
{
    int length;

    length = ft_int_length(n);
    /*if (n < 0)
    {
        n = UINT_MAX + n + 1;
        length = ft_int_length(n);
        ft_putnbr_fd(n, 1); 
    }*/
    if (n < 10)
        ft_putnbr_fd(n, 1);
    else
    {
        ft_putnbr_fd(n / 10, 1);
        ft_putnbr_fd(n % 10, 1);
    }     
    return (length);
}
