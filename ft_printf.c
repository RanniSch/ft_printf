/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:44 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:40:23 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		j;
	int		length;

	va_start(args, format);
	j = 0;
	length = 0;
	while (format[j])
	{
		if (format[j] == '%')
		{
			j++;
			length += ft_format_check(&format[j], args);
		}
		else
		{
			ft_putchar_fd(format[j], 1);
			length++;
		}
		j++;
	}
	va_end(args);
	return (length);
}
