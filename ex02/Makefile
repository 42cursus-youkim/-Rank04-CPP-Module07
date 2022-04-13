NAME := prog.out
CXX := c++
CXXFLAGS := -g -Wall -Wextra -Werror -std=c++98 -pedantic \
			-Iinclude/ -Itemplate/ -Iutil/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

.PHONY: run re leak clean

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

re: clean $(NAME)

leak: $(NAME)
	colour-valgrind ./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)
