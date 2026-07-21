NAME	= convert

CXX		= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -I.

RM		= rm -rf

SRC_DIR	= .
SRC		= $(SRC_DIR)/ScalarConverter.cpp \
		  $(SRC_DIR)/main.cpp

OBJ_DIR	= obj
OBJ		= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re