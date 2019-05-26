# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klekisha <klekisha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 19:18:54 by klekisha          #+#    #+#              #
#    Updated: 2019/05/26 19:38:22 by Dmitry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

PROJ_NAME = fillit

AUTHORS = klekisha\nmcomet

PROJ_DIR = sources

LIBFT_DIR = libft

INCL_DIR = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCL_DIR)

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

LIBFT_OBJECTS = $(LIBFT_SOURCES:%.c=%.o)

LIBFT_DIR_AND_SOURCES = $(LIBFT_SOURCES:%.c= $(LIBFT_DIR)/%.c)

PROJ_DIR_AND_SOURCES = $(PROJ_SOURCES:%.c= $(PROJ_DIR)/%.c)

PROJ_SOURCES = \
		main.c \
		functions.c \
		error.c

PROJ_OBJECTS = $(PROJ_SOURCES:%.c=%.o)

all: $(PROJ_NAME)

$(PROJ_NAME):
		$(CC) $(CFLAGS) $(LIBFT_DIR_AND_SOURCES) $(PROJ_DIR_AND_SOURCES) -o $(PROJ_NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(PROJ_NAME)

re: fclean all
