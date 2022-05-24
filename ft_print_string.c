/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:39:12 by rschlott          #+#    #+#             */
/*   Updated: 2022/05/24 17:39:44 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	length;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (length);
}
