NAME    := philo
CC      := gcc

SRCS    := actions.c checks.c cleaning.c extra_functions.c init.c philosophers.c timer.c
OBJS    := $(SRCS:.c=.o)
HEADER  := philosophers.h

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o3 -o $(NAME) $(OBJS) 

%.o: %.c $(HEADER)
	@$(CC) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

run: $(NAME)
	./$(NAME) 200 800 200 200

re: fclean all