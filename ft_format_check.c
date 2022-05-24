/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:27 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:38:59 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/* checks the format after each % and passes the
    specific arg (Liste von Argumenten) to the
    necessary function. */

int	ft_format_check(const char *format, va_list args)
{
	if (*format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (*format == 'd' || *format == 'i')
		return (ft_print_int((int)va_arg(args, int)));
	if (*format == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (ft_hexadecimal(va_arg(args, unsigned int), 'X'));
	if (*format == 'x')
		return (ft_hexadecimal(va_arg(args, unsigned int), 'x'));
	if (*format == 'p')
		return (ft_ptrtoint(va_arg(args, void *)));
	if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
