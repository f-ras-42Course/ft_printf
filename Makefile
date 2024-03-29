# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/16 14:34:17 by fras          #+#    #+#                  #
#    Updated: 2023/07/08 22:00:29 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall $(INCLUDE)
INCLUDE = -I ./include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c" ! -name "test.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
TESTSRC = test.c


.PHONY: all clean fclean re directories

$(NAME): $(OBJ_DIR) $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJ_DIR): directories

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

all: $(NAME)

directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

clean:
	rm -f $(OBJECTS)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all
