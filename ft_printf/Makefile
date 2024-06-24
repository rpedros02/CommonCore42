# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rucorrei <rucorrei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 20:01:54 by rucorrei          #+#    #+#              #
#    Updated: 2024/06/24 20:49:17 by rucorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 


NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))


CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@cc $(CC_FLAGS) -c $< -o $@
	
$(NAME): $(OBJECTS_PREFIXED)
	@ar rcs $(NAME) $(OBJECTS_PREFIXED)
	@echo "Libft Compiling Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
