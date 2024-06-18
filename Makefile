CC=g++
CFLAGS=-Wall -Werror -Wextra -std=c++98 -pedantic-errors
NAME=$(notdir $(shell pwd))_exec
TEST=test_exec

SRC_DIR=srcs
SRCS=$(shell find $(SRC_DIR) -name '*.cpp')

TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp )
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

OBJ_DIR=obj
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCLUDE= -I include
all: $(NAME)

run: all
	@./$(NAME)

re: fclean run

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D) 
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

-include:$(DEPS)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D) 
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

test: $(TEST)
	./$(TEST)

$(TEST): $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

echo:
	echo $(SRCS)