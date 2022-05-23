/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:56:04 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 14:55:14 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_int_length(long long n)   // long int: so that neg unsigned int length gets counted correctly!
{
    int length;

    length = 0;
    if (n == 0)
        length = 1;
    if (n < 0)
    {
        length++;
        n = n * (-1);
    }
    while (n > 0)
    {
        n = n / 10;
        length++;
    }
    return (length);
}
