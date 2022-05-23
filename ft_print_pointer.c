/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:02:26 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 23:20:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(const char *hexa_num, int i)
{
    char    output;
    int     length;

    length = 0;
    i--;
    /*if (i == 0)
    	length = 1;*/
    hexa_num--;
    ft_putstr_fd("0x", 1);
    while (i > 0)
	{
        output = *hexa_num;
        ft_putchar_fd(output, 1);
		hexa_num--;
        i--;
        length++;
	}
    return (2 + length);
}
