/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:44 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/22 18:50:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*int ft_check_error(const char *format, ...)
{
    va_list     args;
	int		j;
	va_list	args;

    va_start(args, format);
    va_end(args);
    return(0);
}*/

int	ft_printf(const char *format, ...)
{
	va_list args;
    int j;
    int length;
    
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

/*int	main(void)
{
    long int     hd_big;
    long int     hd_small;
    char	*name;
	char	n[6] = "Ranja";

    name = &n[0];
    hd_big = 590;
    hd_small = 590;
	ft_printf("Hexa gr. %X und kl. %x. Position %p \n", hd_big, hd_small, name);

    char	*name;
	char	n[6] = "Ranja";
	char	chr;
	int		age;
    int     base;
    int     pos;
    long int     hd_big;
    long int     hd_small;

	name = &n[0];
	chr = 'a';
	age = 34;
    base = 12;
    pos = 160;
    hd_big = 590;
    hd_small = 590;
	ft_printf("Ich heiße %s mit %c gespeichert unter: %p. Hexa gr. %X und kl.
			%x. Positiv: %u, Alter %d, %% und %i.\n", name, chr, name, hd_big,
			hd_small, pos, age, base);  
	return (0);
}*/
