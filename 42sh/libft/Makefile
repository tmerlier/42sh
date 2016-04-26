# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazie <amazie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 13:59:38 by amazie            #+#    #+#              #
#    Updated: 2014/06/14 14:19:22 by amazie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# option

CC = gcc
FLAGS = -Wall -Werror -Wextra

# path

HEADER = includes/
SRCDIR = sources/

# Files

LIB = libft.a
SRC = ft_strlen.c \
	  ft_del.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_isupper.c \
	  ft_islower.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_atoi.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_strplen.c \
	  get_next_line.c \
	  ft_isspace.c \
	  strisint.c \
	  ft_strword.c \
	  ft_putstr_color.c \
	  ft_puttext_fd.c

O_FILES = $(SRC:.c=.o)

STATE = Updated

all: init $(LIB)

init:
	@clear

$(LIB): $(O_FILES)
	@ranlib $(LIB)

%.o: $(SRCDIR)%.c
	@echo -n
	@$(CC) -o $@ $(FLAGS) -I $(HEADER) -c $<
	@ar -rcs $(LIB) $@

clean:
	@rm -f $(O_FILES)

fclean: clean
	$(eval STATE = Created)
	@rm -f $(LIB)

re: fclean all

