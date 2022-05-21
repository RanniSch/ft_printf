/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:44 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/21 17:32:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>  //test mit printf, muss dann raus

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

void ft_hexadecimal_big(unsigned int hd)
{
    long int quo;
    int i;
    int j;
    int temp;

    i = 1;
    char hexadecNum[100];
    char result[100];
    quo = hd;
    while(quo!=0)
    {
        temp = quo % 16;
        if( temp < 10)
            temp = temp + 48;   // + 48 to get the correct number (0 to 9) in the ascii code else it would f.e. not a "4" but a "EOT ^D".
        else
            temp = temp + 55;   // + 55 to get the letter for (10 to 16) equals (A to F).
        hexadecNum[i] = temp;
        quo = quo / 16;
        i++;
    }
    j = i - 1;
    i = 0;
    while (j > 0)
    {
        result[i] = hexadecNum[j];
        ft_putchar_fd(result[i], 1);
        j--;
    }
}

void ft_hexadecimal_small(unsigned long hds)        // for error management hds not bigger than max int for %x and %X
{
    unsigned long quo;
    int i;
    int j;
    int temp;

    i = 1;
    char hexadecNum[100];
    char result[100];
    quo = hds;
    while(quo!=0)
    {
        temp = quo % 16;
        if( temp < 10)
            temp = temp + 48;           // + 48 to get the correct number (0 to 9) in the ascii code else it would f.e. not a "4" but a "EOT ^D".
        else
            temp = temp + 55 + 32;          // + 55 to get the letter for (10 to 16) equals (A to F); + 32 to make it small
        hexadecNum[i] = temp;
        quo = quo / 16;
        i++;
    }
    j = i - 1;
    i = 0;
    while (j > 0)
    {
        result[i] = hexadecNum[j];
        ft_putchar_fd(result[i], 1);
        j--;
    }
}

int	ft_printf(const char *format, ...)
{
    int				j;
	unsigned int	i;
    unsigned long   hex_address;
    long int        hd;
    long int        hds;
    void            *p;
	char			*s;
	char			c;
	va_list			args;

	va_start(args, format); // args ist eine Liste von Elementen und format ist der erste Eintrag der Liste; Startet beim format (erster Eintrag der Liste!!! args sind die '...' (Argumente, die hinter dem String eingegeben werden); format ist Länge des Strings
    j = 0;                                  // geht durch den ersten Eintrag meiner Liste durch (erster String)!
	while (format[j] != '\0')
	{
		if (format[j] == 's' && format[j - 1] == '%')
		{
			s = va_arg(args, char *);           // args = Liste der Argumente; Pointer zum nächsten (hier zweiten) Eintrag von der Liste; Beim Ausführen von va_arg holt sich va_arg automatisch das nächste Inputargument (hier das zweite).
			ft_putstr_fd(s, 1);
			j++;
			continue ;
		}
		if (format[j] == 'c' && format[j - 1] == '%')
		{
			c = va_arg(args, int);         // 'char' is promoted to 'int' when passed through '...' daher muss int rein, obwohl char! Beim Ausführen von va_arg holt sich va_arg automatisch das nächste Inputargument aus der Liste (hier das dritte).
            ft_putchar_fd(c, 1);
			j++;
			continue ;
		}
		if ((format[j] == 'd' || format[j] == 'i') && format[j - 1] == '%')
		{
			i = va_arg(args, int);
            ft_putnbr_fd(i, 1);
			j++;
			continue ;
		}
        if (format[j] == 'u' && format[j - 1] == '%')
		{
			i = va_arg(args, int);
            ft_putnbr_fd(i, 1);
			j++;
			continue ;            
		}
        if (format[j] == 'X' && format[j - 1] == '%')
		{
			hd = va_arg(args, int);
            ft_hexadecimal_big(hd);
			j++;
			continue ;
		}
        if (format[j] == 'x' && format[j - 1] == '%')
		{
			hds = va_arg(args, int);
            ft_hexadecimal_small(hds);
			j++;
			continue ;
		}
        if (format[j] == 'p' && format[j - 1] == '%')
		{
			p = va_arg(args, void *);
            //printf("\n\n\n\n pointer address hexadec:  %p \n\n\n\n", p);
            //ft_print_pointer(p);
            hex_address = (unsigned long)p;
            ft_putstr_fd("0x", 1);
            ft_hexadecimal_small(hex_address);
			j++;
			continue ;
		}
        if (format[j] == '%' && format[j - 1] == '%')
		{
            ft_putchar_fd('%', 1);
			j++;
			continue ;
		}
		if (format[j] != '%')
			ft_putchar_fd(format[j], 1);
		j++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char	*name;
	char	n[6] = "Ranja";
	//char	chr;
	int		age;
    int     base;
    int     pos;
    long int     hd_big;
    long int     hd_small;

	name = &n[0];
	//chr = 'a';
	age = -34;
    base = 12;
    pos = 160;
    hd_big = 6356726;
    hd_small = 590;
    //printf("\n%p\n", name);
	ft_printf("Ich bin %p und %X mit %x und %u bin %d Jahre %% alt %i.\n", name, hd_big, hd_small, pos, age, base);     // Erste Eintrag in meiner Liste ist der komplette String, zweiter Eintrag ist %s, dritter Eintrag %c und vierter %d.
	return (0);
}
