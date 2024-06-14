CC	= c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic-errors

NAME := $(notdir $(shell pwd))
SRCS := $(wildcard *.cpp)

OBJDIR	:= obj/
OBJS	:= $(SRCS:%.cpp=$(OBJDIR)%.o)

CYAN	:= "\033[0;36m"
PURPLE	:= "\033[0;35m"
CYAN	:= $(PRUPLE)
RESET	:= "\033[00m"



all: $(NAME)

run: re
	@echo $(PURPLE)Running ./$(NAME) ... $(RESET)"\n"
	@./$(NAME)

$(NAME): $(OBJS)
	@echo $(PURPLE)Compiling ./$(NAME) ...
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@echo $(CYAN)"Done !\n" $(RESET) 

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D);
	@$(CC) -c $(CFLAGS) -MMD -MP $< -o $@

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