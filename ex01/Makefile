NAME	= exec
RM 		= rm -rf


CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror -I.

SRC_DIR = .
OBJ_DIR	= obj

SRC		=	$(SRC_DIR)/Serializer.cpp \
			$(SRC_DIR)/main.cpp

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