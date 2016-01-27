ifndef DBUG
	CFLAGS = -Wall -Werror -Wextra
endif

NAME = Test_prog
SRC = main.c \
	  reader.c \


OBJ = $(SRC:.c=.o)

SRCDIR 	= ./src/
INCDIR 	= ./includes/
LIBDIR	= ./libft
OBJDIR  = ./objs/

SRCS   	= $(addprefix $(SRCDIR), $(SRC))
OBJS   	= $(addprefix $(OBJDIR), $(OBJ))

LIBFLAGS = -L$(LIBDIR) -lft -L/usr/lib -ltermcap

LBLUE	= \033[1;34m
LGREEN	= \033[1;32m
NC		= \033[0m

.PHONY : all lib norme clean fclean re

all: lib prefix $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJS)
	@echo "$(LBLUE)$(NAME) a ete cree !$(NC)"

$(OBJDIR)%.o: $(SRCDIR)%.c	
	@gcc $(CFLAGS) -I $(LIBDIR) -I $(INCDIR) -c -o $@ $^
	@echo "\t$(LBLUE)$@$(NC) ... [$(LGREEN)OK$(NC)]"

lib: 
	@Make -C libft/

norme:
	norminette $(SRCDIR)*.c $(INCDIR)*.h

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "$(LBLUE)Grand menage$(NC)"

re: fclean all

prefix:
	@mkdir -p $(OBJDIR)
	@echo "$(LBLUE)Compilation de $(NAME)$(NC) ..."
