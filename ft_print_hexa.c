/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:07:22 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/21 22:25:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
/* prints hexa for %x, %X and %p. */

void	ft_print_hexa(const char *hexadecNum, int i)
{
	int	j;

	j = i - 1;
	i = 0;
	while (j > 0)
	{
		result[i] = hexadecNum[j];
		ft_putchar_fd(result[i], 1);
		j--;
	}
}
