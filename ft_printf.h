/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:00:16 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:40:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_format_check(const char *format, va_list args);
int		ft_hexadecimal(unsigned int hd, char c);
void	ft_print_hexa(unsigned int hd, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_int_length(long long n);
int		ft_print_char(char c);
int		ft_print_int(int n);
int		ft_print_string(char *s);
int		ft_strlen(char *s);
int		ft_print_unsigned_int(unsigned int n);
void	ft_print_pointer(unsigned long hex_pt);
int		ft_hexadecimal_pointer(unsigned long hex_pt);
int		ft_ptrtoint(void *pt);

#endif
