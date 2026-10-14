
NAME = PmergeMe

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -fsanitize=address -g3

CPP = c++

SRCS =PmergeMe.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: clean