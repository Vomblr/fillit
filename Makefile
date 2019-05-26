# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 19:18:54 by klekisha          #+#    #+#              #
#    Updated: 2019/05/25 19:04:40 by klekisha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fillit

AUTHORS = klekisha\nmcomet

FILLIT_DIR = fillit

LIBFT_DIR = libft

INCL_DIR = includes

WFLAGS = -Wall -Wextra -Werror -I $(INCL_DIR)

DFLAGS = -g

OFLAGS = -O3

LIBFT_SOURCES =	\
		ft_atoi.c \
  		ft_bzero.c \
  		ft_isalnum.c \
  		ft_isalpha.c \
  		ft_isascii.c \
  		ft_isdigit.c \
  		ft_isprint.c \
  		ft_isspace.c \
  		ft_itoa.c \
  		ft_lstadd.c \
  		ft_lstdel.c \
  		ft_lstdelone.c \
  		ft_lstiter.c \
  		ft_lstmap.c \
  		ft_lstnew.c \
  		ft_memalloc.c \
  		ft_memccpy.c \
  		ft_memchr.c \
  		ft_memcmp.c \
  		ft_memcpy.c \
  		ft_memdel.c \
  		ft_memmove.c \
  		ft_memset.c \
 		ft_putchar.c \
  		ft_putchar_fd.c \
  		ft_putendl.c \
  		ft_putendl_fd.c \
  		ft_putnbr.c \
 		ft_putnbr_fd.c \
  		ft_putstr.c \
  		ft_putstr_fd.c \
  		ft_strcat.c \
  		ft_strchr.c \
  		ft_strclr.c \
  		ft_strcmp.c \
  		ft_strdel.c \
  		ft_strdup.c \
  		ft_strequ.c \
  		ft_striter.c \
  		ft_striteri.c \
  		ft_strjoin.c \
  		ft_strlcat.c \
  		ft_strlen.c \
 		ft_strmap.c \
  		ft_strmapi.c \
  		ft_strncat.c \
  		ft_strncmp.c \
  		ft_strnequ.c \
 		ft_strnew.c \
  		ft_strnjoin.c \
  		ft_strnstr.c \
  		ft_strrchr.c \
  		ft_strsplit.c \
  		ft_strstr.c \
  		ft_strsub.c \
  		ft_strtrim.c \
  		ft_tolower.c \
  		ft_toupper.c \
  		ft_strcpy.c \
  		ft_strncpy.c \
  		ft_abs.c \
		ft_count_words.c \
		ft_recursive_power.c \
		ft_sqrt.c

LIBFT_OBJECTS = $(LIBFT_SOURCES:.c=.o)

# gcc main.c get_next_line.c libft/*.c -o GNL
all: $(NAME)

$(NAME):
		$(CC) $(WFLAGS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
