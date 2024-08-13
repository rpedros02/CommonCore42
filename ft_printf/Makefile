# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 18:29:07 by rucorrei          #+#    #+#              #
#    Updated: 2024/08/13 16:55:31 by rucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifneq (,$(findstring xterm,${TERM}))
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	BLUE         := $(shell tput -Txterm setaf 6)
	RESET := $(shell tput -Txterm sgr0)
else
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	BLUE         := ""
	RESET        := ""
endif

# set target color
TARGET_COLOR := $(BLUE)

POUND = \#

SRCS = 	ft_print_hex.c		\
		ft_print_ptr.c		\
		ft_print_unsigned.c	\
		ft_printf_utils.c	\
		ft_printf.c			

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = src/
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(NAME): $(OBJECTS_PREFIXED)
	@make -C ./libft && cp ./libft/libft.a $@
	@echo "$(BLUE)$(POUND)Copying libft.a Done !$(RESET)"
	@ar rcs $(NAME) $(OBJECTS_PREFIXED)
	@echo "$(GREEN)$(POUND)Printf Compiling Done !$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(YELLOW)$(POUND)Compiling: $<$(RESET)"
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	@make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
	@echo "$(RED)$(POUND)Cleaning Done !$(RESET)"	

re: fclean all

