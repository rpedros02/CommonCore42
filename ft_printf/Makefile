# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 18:29:07 by rucorrei          #+#    #+#              #
#    Updated: 2024/06/25 10:06:30 by rucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 	ft_print_hex.c		\
		ft_print_ptr.c		\
		ft_print_unsigned.c	\
		ft_printf_utils.c	\
		ft_printf.c			

NAME = libftprintf.a
CC_FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./includes
SRCS_DIR = src/
OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(NAME): $(OBJECTS_PREFIXED)
	@make -C ./libft && cp ./libft/libft.a $@
	@echo "Copying libft.a Done !"
	@ar rcs $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Compiling Done !"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@cc $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	@make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

