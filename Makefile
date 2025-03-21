CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex
# HEADERS = -I ./include -I ./display

SRC = 	src/pipex.c\
		disp_array.c\
		src/free_ar.c\
		display/ft_printf.c\
		display/pf_utils.c\
		display/pf_utils1.c\
		libftneed/ft_split.c\
		libftneed/ft_strdup.c\
		libftneed/ft_strjoin.c\
		libftneed/ft_bzero.c\
		libftneed/ft_calloc.c\
		libftneed/ft_strlen.c\
		libftneed/ft_strnstr.c

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
ORANGE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

OBJ = $(SRC:.c=.o)

all : $(NAME)



$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "\n"
	@echo "$(MAGENTA)██████╗ ██╗██████╗ ███████╗██╗  ██╗"
	@echo "$(MAGENTA)██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	@echo "$(MAGENTA)██████╔╝██║██████╔╝█████╗   ╚███╔╝ "
	@echo "$(MAGENTA)██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ "
	@echo "$(MAGENTA)██║     ██║██║     ███████╗██╔╝ ██╗"
	@echo "$(MAGENTA)╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝"
	@echo "$(GREEN)\n--The Makefile of [PIPEX] has been compiled!--"
	@echo "$(YELLOW)=> Usage: ./pipex infile cmd1 cmd2 outfile\n$(DEF_COLOR)"

%.o : %.c include/pipex.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "$(GRAY)clean…"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

ac : all clean
