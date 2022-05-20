/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:20:44 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/20 14:20:36 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

/*size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count) != '\0')
		count++;
	return (count);
}*/

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

/*int ft_memorylength(const char *format, ...)
{
    int size_format;
    int size_args;
    int j;
    char    *s;
    va_list			args;

	va_start(args, format);
    size_format = 0;
    size_args = 0;
    size_format = ft_strlen(format);
    j = 0;
    while (format[j] != '\0')
    {
        if (format[j] == 's' && format[j - 1] == '%')
		{
			s = va_arg(args, char *);
            size_args = ft_strlen(s);
            if (size_format >= 2)
                size_format = size_format - 2;
            j++;
            continue ;
        }
        j++;
    }
    va_end(args);

{
   va_list  args;
   int j;
   int num_args
   
   num_args = 0;
   va_start(args, format); //va_start used to start before accessing arguments
   while (j < format)
   {
       num_args += va_arg(args, int);
       j++;
   }
   va_end(args); //va_end used after completing access of arguments
   return (num_args);
}
}*/

/** Hexadecimal converter und print **/

int	ft_printf(const char *format, ...)
{
    int				j;
	unsigned int	i;
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
	char	chr;
	int		age;
    int     base;

	name = &n[0];
	chr = 'a';
	age = 34;
    base = 012;
	ft_printf("Ich bin %s mit %c und bin %d Jahre alt %i.\n", name, chr, age, base);     // Erste Eintrag in meiner Liste ist der komplette String, zweiter Eintrag ist %s, dritter Eintrag %c und vierter %d.
	return (0);
}
