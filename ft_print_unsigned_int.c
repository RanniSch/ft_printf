/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:24:38 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 14:27:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_print_unsigned_int(unsigned int n)
{
    int length;

    length = ft_int_length(n);
    if (n < 10)
        ft_putnbr_fd(n, 1);
    else
    {
        ft_putnbr_fd(n / 10, 1);
        ft_putnbr_fd(n % 10, 1);
    }     
    return (length);
}

/*int main(void)
{
    int a;
    int length;

    a = -5;
    printf("\n%d\n", a);
    length = ft_print_unsigned_int(a);
    printf("\n%d\n", length);
    return(0);
}*/