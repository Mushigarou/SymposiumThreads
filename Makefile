NAME  := philo

CC := cc

CFLAGS := -Wall -Werror -Wextra #-fsanitize=thread #adress

SRC :=	src/main.c \
		src/utils.c \
		src/routine.c \
		src/initialize_simulation.c \
		circular_linked_list/create_node.c \
		circular_linked_list/insert_back.c \
		circular_linked_list/clear_list.c \
		

OBJ_DIR := obj

OBJ = $(patsubst %, $(OBJ_DIR)/%, $(SRC:.c=.o))

HEADERS_DIR := inc

HEADERS_FILE := inc/philosophers.h

RM := rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) 

$(OBJ_DIR)/%.o : %.c $(HEADERS_FILE)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

# .SILENT : re fclean clean all
