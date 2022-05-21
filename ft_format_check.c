/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:27 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/21 22:38:13 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/* checks the format after each % and passes the
    specific arg (Liste von Argumenten) to the
    necessary function. */

int	ft_format_check(const char *format, va_list args)
{
	unsigned long	hex_address;

	if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);      // wahrscheinlich kann ich das nicht so in void Functions passen. Also Erweiterung in neue Funktion!!!
	if (*format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (*format == 'u')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (*format == 'X')
		ft_hexadecimal_big(va_arg(args, int));
	if (*format == 'x')
		ft_hexadecimal_small(va_arg(args, int), 0);
	if (*format == '%')
		ft_putchar_fd('%', 1);
	if (*format == 'p')
	{
		hex_address = (unsigned long)va_arg(args, void *);
		ft_hexadecimal_small(hex_address, 1);
	}
	return (0);
}
