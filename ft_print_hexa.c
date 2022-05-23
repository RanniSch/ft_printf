/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:07:22 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 22:56:14 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* prints hexa (reverse printing) for %x, %X and %p. 
	i is needed to stop the reverse printing in time. */

int	ft_print_hexa(const char *hexa_num, int i)
{
    char    output;
    int     length;

    length = 0;
    i--;
    /*if (i == 0)
    	length = 1;*/
    hexa_num--;
    while (i > 0)
	{
        output = *hexa_num;
        ft_putchar_fd(output, 1);
		hexa_num--;
        i--;
        length++;
	}
    return (length);
}
