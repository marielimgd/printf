# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 16:48:47 by mmariano          #+#    #+#              #
#    Updated: 2024/11/20 19:39:05 by mmariano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

# Rule to build the object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build libft (must be done before building libftprintf.a)
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Rule to build the final static library (libftprintf.a)
$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)

# Default target is 'all', which depends on $(NAME)
all: $(NAME)

# Rule to remove object files
clean:
	rm -f $(OBJS)

# Rule to remove both object files and the final static library
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to clean and then rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
