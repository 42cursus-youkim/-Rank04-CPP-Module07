NAME := prog.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 \
			-Iinclude/ -Itemplate/ -Iutil/

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:%.cpp=%.o)

.PHONY: run re test clean

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

re: clean $(NAME)

clean:
	rm -f $(OBJ) $(NAME)
