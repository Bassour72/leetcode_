CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
DEBUG_FLAGS = -fsanitize=address -g3
VALGRIND = valgrind --leak-check=full  --track-fds=all 
FILE ?= main

all:
ifeq ($(FILE),main)
	$(error Please specify a file using 'make FILE=filename')
else
	@echo "Running with custom file: $(FILE)"
	$(CXX) $(CXXFLAGS) $(FILE).c++ -o $(FILE)
	./$(FILE)
endif

leaks:
ifeq ($(FILE),main)
	$(error Please specify a file using 'make leaks FILE=filename')
endif
	$(CXX) $(CXXFLAGS) $(FILE).c++ -o $(FILE)
	$(VALGRIND) ./$(FILE)

debug:
ifeq ($(FILE),main)
	$(error Please specify a file using 'make debug FILE=filename')
endif
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) $(FILE).c++ -o $(FILE)
	./$(FILE)

clean:
	rm -f $(FILE)
	@echo "Cleaned up $(FILE)"

.PHONY: leaks debug clean
