/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:44 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/19 15:38:12 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	while (*(s + i) != 0)
	{
		c = *(s + i);
		write(fd, &c, 1);
		i++;
	}
}

int ft_printf(char *s, char *name, char chr, int age)
{
    int i;

    i = 0;
    while(s[i])
        if (s[i] != '%')
            ft_putchar_fd(s[i], 20);
        if (s[i] == 's' && s[i] - 1 == '%')
            ft_putstr_fd(name, 5);
        if (s[i] == 'c' && s[i] - 1 == '%')
            ft_putchar_fd(chr, 1);
        if (s[i] == 'd' && s[i] - 1 == '%')
            ft_putnbr_fd(age, 2);
    i++;
    return(0);
}

int main(void)
{
    char    *name;
    char    *s;
    char    str[30] = "Ich bin %s mit %c und %d.";
    char    n[5] = "Ranja";
    char    chr;
    int     age;

    s = &str[0];
    name = &n[0];
    chr = 'a';
    age = 34;
    ft_printf(s, name, chr, age);
    return(0);
}
