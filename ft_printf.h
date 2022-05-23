/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:00:16 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/23 14:55:58 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format_check(const char *format, va_list args);
int 	ft_hexadecimal_big(unsigned int hd);
int 	ft_hexadecimal_small(unsigned long hds, int ptr_yes);
int 	ft_print_hexa(const char *hexa_num, int i);
void 	ft_putchar_fd(char c, int fd);
void 	ft_putstr_fd(char *s, int fd);
void 	ft_putnbr_fd(int n, int fd);
int     ft_int_length(long long n);
int     ft_print_char(char c);
int     ft_print_int(int n);
int     ft_print_string(char *s);
int     ft_strlen(char *s);
int     ft_print_unsigned_int(unsigned int n);

#endif
