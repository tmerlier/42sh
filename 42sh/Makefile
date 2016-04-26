# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/20 14:06:06 by tmerlier          #+#    #+#              #
#    Updated: 2014/06/19 18:32:27 by tmerlier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

DIRLIB = libft/

DIRSRC = srcs/

DIRH = includes/

SRC = main.c \
	  lexer.c \
	  lexer_tools.c \
	  get.c \
	  del.c \
	  history.c \
	  cursor_move.c \
	  erase_input.c \
	  signal.c \
	  prompt.c \
	  lst_to_str.c \
	  lst_cursor.c \
	  lst_chara.c \
	  singleton.c \
	  get_line.c \
	  init_env.c \
	  init_term.c \
	  tool.c \
	  error.c \
	  parser.c \
	  exec_cmd.c \
	  parse_error.c \
	  parser_handling.c \
	  open_close.c \
	  exec_pipe.c \
	  exec_pars.c \
	  exec.c \
	  build_env.c \
	  build_echo.c \
	  free.c \
	  isaccess.c \
	  builtin.c \
	  setenv.c \
	  unset_env.c \
	  build_echo.c \
	  cd.c \
	  cd_access.c \
	  exit.c \
	  builtin_env.c \
	  tool_env_arg.c \
	  binaries.c

OBJ = $(SRC:.c=.o)

all: init $(NAME)

init:
	@echo "\033[0;32m 					$(NAME) PROJECT\033[0m"

$(NAME): $(OBJ)
	@make -s -C $(DIRLIB)
	@$(CC) $(FLAGS) -o $(NAME) $^ -I$(DIRLIB) -I$(DIRH) -L$(DIRLIB) -lft -ltermcap
	@echo "\033[1;32m$(NAME): OK\033[0m"

%.o: $(DIRSRC)%.c
	@echo -n .
	@$(CC) $(FLAGS) -o $@ -c $< -I$(DIRLIB)$(DIRH) -I$(DIRH)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(DIRLIB)
	@echo "\033[4;32mDeleted:\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@make -C $(DIRLIB) $@
	@rm -f $(NAME)
	@echo "\033[4;32mDeleted:\033[0;33m $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
