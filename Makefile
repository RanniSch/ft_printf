# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 11:02:29 by rschlott          #+#    #+#              #
#    Updated: 2022/05/23 23:18:56 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar -rcsv
RM		= 	rm -f

NAME	= 	libftprintf.a
INCLUDE	= 	ft_printf.h

STD		= 	ft_format_check.c	\
			ft_hexadecimal_big.c	\
			ft_hexadecimal_small.c	\
			ft_print_hexa.c	\
			ft_printf.c	\
			ft_putchar_fd.c	\
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_int_length.c	\
			ft_print_char.c	\
			ft_print_int.c	\
			ft_print_string.c	\
			ft_strlen.c	\
			ft_print_unsigned_int.c	\
			ft_print_pointer.c	\
			ft_hexadecimal_pointer.c	\

OBJ		= 	${STD:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
			$(AR) $(NAME) $(OBJ)
			
clean: 
			$(RM) $(OBJ)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re bonus