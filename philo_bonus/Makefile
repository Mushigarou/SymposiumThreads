NAME := philo_bonus

CC := cc

SRC :=	main.c \
		utils.c

OBJ := $(patsubst %.c, obj/%.o, $(SRC))

OBJ_DIR := obj/

CFLAGS := -Wall -Werror -Wextra

HEADERS = philosophers_bonus.h

RM := rm -rf

all : $(NAME)
	
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : %.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re clean fclean all

