/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:27 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/22 21:30:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* checks the format after each % and passes the
    specific arg (Liste von Argumenten) to the
    necessary function. */

int	ft_format_check(const char *format, va_list args)
{
	unsigned long	hex_address;

	if (*format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (*format == 'd' || *format == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (*format == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (ft_hexadecimal_big(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (ft_hexadecimal_small(va_arg(args, unsigned int), 0));
	if (*format == 'p')
	{
		hex_address = (unsigned long)va_arg(args, void *);
		return (ft_hexadecimal_small(hex_address, 1));
	}
	if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}		
	return (0);
}
