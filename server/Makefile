CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

INCLUDE=-Iinclude

NAME := $(notdir $(shell pwd))

SRC_DIR := srcs
SRCS := $(shell find srcs -name '*.cpp')

OBJ_DIR	:= obj
OBJS	:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CYAN	:= "\033[0;36m"
PURPLE	:= "\033[0;35m"
CYAN	:= $(PRUPLE)
RESET	:= "\033[00m"

all: $(NAME)

echo:
	@echo $(SRCS)
	@echo $(OBJS)

run: re
	@echo $(PURPLE)Running ./$(NAME) ... $(RESET)"\n"
	@./$(NAME)

$(NAME): $(OBJS)
	@echo $(PURPLE)Compiling ./$(NAME) ...
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS)
	@echo $(CYAN)"Done !\n" $(RESET) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D);
	@$(CC) -c $(CFLAGS) $(INCLUDE) -MMD -MP $< -o $@

-include $(DEPS)

clean:
	@echo $(PURPLE)Deleting Object files $(RESET) 
	@rm -f $(OBJS)

fclean: clean
	@echo $(PURPLE)Deleting ./$(NAME) $(RESET) 
	@rm -rf $(NAME)

re: fclean $(NAME)

leak: re
	leaks -atExit -- ./$(NAME)
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME):