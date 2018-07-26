NAME = the_legend_27

SOURCES =	main_test.c \
			print.c \
			get_possession.c \
			board_init.c \
			calc_score.c \
			get_piece.c \
			malloced_structures.c \

LIBDIR = libft

SDIR = srcs

ODIR = bin

CFLAGS = -Werror -fsanitize=address,undefined

INCDIR = includes

LDFLAGS = -L$(LIBDIR) -lft

CC = gcc

SRCS = $(addprefix $(SDIR)/, $(SOURCES:.c=.c))

OBJS = $(addprefix $(ODIR)/, $(SOURCES:.c=.o))

OK = echo "[32m OK ✓ [0m"

all: lib mkbin $(NAME)

lib:
	@make -C $(LIBDIR)

mkbin:
	@mkdir -p $(ODIR)


$(NAME): $(OBJS)
	@ echo "[35mEntering Filler Makefile...[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INCDIR) $(LDFLAGS)
	@$(OK)

$(ODIR)/%.o : $(SDIR)/%.c
	@ echo "[34mAssembling Filler object: [0m" $@
	@ $(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	@ echo "[31mDeleted object directory... [0m"
	@/bin/rm -rf $(ODIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
