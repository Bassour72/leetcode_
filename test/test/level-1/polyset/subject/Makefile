NAME        = program
CXX         = g++
CXXFLAGS    = -Wall -Wextra -Werror -g -std=c++98

# Analysis Tools
VALGRIND    = valgrind -s --leak-check=full --show-leak-kinds=all --track-fds=yes
ASAN_FLAGS  = -fsanitize=address -fno-omit-frame-pointer -g3

SRCS        = tree_bag.cpp array_bag.cpp set.cpp searchable_tree_bg.cpp searchable_array_bag.cpp main.cpp
OBJS        = $(SRCS:.cpp=.o)

# --- Rules ---
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Use the Valgrind variable
leak: fclean $(NAME)
	$(VALGRIND) ./$(NAME)

# Use the ASan variable
debug: fclean
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) $(SRCS) -o $(NAME)
	./$(NAME)

fclean:
	rm -f $(OBJS) $(NAME)

.PHONY: all leak debug fclean

