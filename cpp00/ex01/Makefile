COMPILER = c++
COMPILE_FLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES = "Contact.hpp PhoneBook.hpp"

CPP_FILES = Contact.cpp PhoneBook.cpp main.cpp
OBJ_FILES = $(CPP_FILES:.cpp=.o)

NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(COMPILER) $(COMPILE_FLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp
	@echo "[COMPILE] $<"
	@$(COMPILER) $(COMPILE_FLAGS) -c $< -o $@ -I$(INCLUDES)

clean:
	@echo "[CLEAN] removing object files"
	@rm -f $(OBJ_FILES)

fclean:
	@echo "[FCLEAN] removing binary & object files"
	@rm -f $(NAME)
	@rm -f $(OBJ_FILES)

re: fclean all

.PHONY: all clean fclean re
