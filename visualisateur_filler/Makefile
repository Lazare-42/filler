NAME = visualisateur

SOURCES =	main_test.c \
			get_possession.c \
			board_init.c \
			malloced_structures.c \
			fast_gnl.c \
			image_handler.c \
			board_update.c \
			board_distance_update_1.c \
			board_distance_update_2.c \
			possession_update.c \
			screen_display.c \
			pass_pieces_or_find_winner.c \

LIBDIR = libft

MINILIBXDIR = minilibx_macos

SDIR = srcs

ODIR = bin

CFLAGS = -Werror -fsanitize=address,undefined -Wall -Wextra

INCDIR = includes

LDFLAGS = -L$(LIBDIR) -lpthread -lft -L$(MINILIBXDIR) -lmlx -framework AppKit -framework OpenGL

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
