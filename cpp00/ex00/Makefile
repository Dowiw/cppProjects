# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmonjard <kmonjard@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 14:39:32 by kmonjard          #+#    #+#              #
#    Updated: 2026/05/26 14:39:35 by kmonjard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = c++
CPP_FLAGS = -g -Wall -Werror -Wextra -std=c++98

CPP_FILES = megaphone.cpp

CPP_OBJ = $(CPP_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(CPP_OBJ)
	@$(CXX) $(CPP_FLAGS) $(CPP_OBJ) -o $(NAME)

%.o: %.c
	@echo "Compiling $<..."
	@$(CXX) $(CPP_FLAGS) -c $< -o $@

clean:
	@echo "Deleting object files in ex00..."
	@rm -f $(CPP_OBJ)

fclean:
	@echo "Deleting all binaries in ex00..."
	@rm -f $(NAME)
	@rm -f $(CPP_OBJ)

re: fclean all

.PHONY: all clean fclean re
