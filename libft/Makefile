# **************************************************************************** # #                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 14:56:05 by lazrossi          #+#    #+#              #
#    Updated: 2018/06/25 10:33:59 by lazrossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =			ft_advance_for_quotes.c \
				ft_printbits.c \
      			ft_atof.c \
      			ft_atoi.c \
				ft_strdiff.c \
      			ft_bzero.c \
      			ft_check_endianness.c \
      			ft_debug.c \
      			ft_del_tab_str.c \
      			ft_double_size.c \
      			ft_freetables.c \
      			ft_int_size.c \
      			ft_isalnum.c \
      			ft_isalpha.c \
      			ft_isascii.c \
      			ft_isdigit.c \
      			ft_isprint.c \
      			ft_itoa.c \
      			ft_joinfree_heapstr_stackstr.c \
      			ft_joinfree_stackstr_heapstr.c \
      			ft_lstadd.c \
      			ft_lstdel.c \
      			ft_lstdelone.c \
      			ft_lstiter.c \
      			ft_lstmap.c \
      			ft_lstnew.c \
      			ft_ltoa.c \
      			ft_memalloc.c \
      			ft_memccpy.c \
      			ft_memchr.c \
      			ft_memcmp.c \
      			ft_memcpy.c \
      			ft_memdel.c \
      			ft_memmove.c \
      			ft_memset.c \
      			ft_mins_to_caps.c \
      			ft_myexit.c \
      			ft_mystriter.c \
      			ft_printtables.c \
      			ft_put_error_return_null.c \
      			ft_put_fatal_error.c \
      			ft_putabs.c \
      			ft_putchar.c \
      			ft_putchar_fd.c \
      			ft_putendl.c \
      			ft_putendl_fd.c \
      			ft_putnbr.c \
      			ft_putnbr_fd.c \
      			ft_putstr.c \
      			ft_putstr_fd.c \
      			ft_putwhites.c \
      			ft_s_base_converter.c \
      			ft_split_char.c \
      			ft_split_whitespaces.c \
      			ft_split_whitespaces_nokots.c \
      			ft_str_is_printable.c \
      			ft_str_isalpha.c \
				ft_str_mins_to_caps.c \
      			ft_strcat.c \
      			ft_strchr.c \
      			ft_strclr.c \
      			ft_strcmp.c \
      			ft_strcpy.c \
      			ft_strdel.c \
      			ft_strdup.c \
      			ft_strdupfrom_free.c \
      			ft_strequ.c \
      			ft_striter.c \
      			ft_striteri.c \
      			ft_strjoin.c \
      			ft_strjoinfree.c \
      			ft_strjoinfree_char_str.c \
      			ft_strjoinfree_one.c \
      			ft_strjoinfree_str_char.c \
      			ft_strlcat.c \
      			ft_strlen.c \
      			ft_strmap.c \
      			ft_strmapi.c \
      			ft_strncat.c \
      			ft_strncmp.c \
      			ft_strncpy.c \
      			ft_strndup.c \
      			ft_strndup_free.c \
      			ft_strnequ.c \
      			ft_strnew.c \
      			ft_strnstr.c \
      			ft_strrchr.c \
      			ft_strsplit.c \
      			ft_strstr.c \
				ft_strstr_whilestr.c \
      			ft_strstrstr.c \
				ft_strstrchr.c \
      			ft_strsub.c \
      			ft_strtrim.c \
      			ft_symetric_byte_swap.c \
      			ft_tab_replacestr.c \
      			ft_tabdel.c \
      			ft_tabdup.c \
      			ft_tabdup_add_free.c \
      			ft_tabdup_and_add.c \
      			ft_tabsize.c \
      			ft_tolower.c \
      			ft_toupper.c \
      			ft_u_base_converter.c \
      			int_ft_putchar.c \
				 ft_printf.c \
				get_modifiers.c \
				stack_management.c \
				parsing.c \
				precision_width.c \
				base_converter.c \
				wide_char.c \
				store_nbr_data.c \
				store_char_data.c \
				bonus_colors_formatting.c \

# CC = gcc -Wall -Wextra -Werror -c -g

CC = gcc -Wall -Werror -Wextra -c

#DEBUG = ""
#if ${DEBUG}
#	CC += ASAN	

ODIR = bin_libft

S_LIB_DIR = srcs

LIBFT_OBJECT = $(addprefix $(ODIR)/, $(SRCS:.c=.o))

CLEAN = rm -rf $(ODIR)

ARCH = ar rc

all: mkbin $(NAME)

mkbin:
	@mkdir -p $(ODIR)

$(NAME): $(LIBFT_OBJECT)
	@echo "\x1B[33;4mCompiled with the rule\x1B[0m :" ${CC}
	@ echo "[35mLibft archived.[0m"
	@$(ARCH) $(NAME) $(LIBFT_OBJECT)
	@$(OK)

$(ODIR)/%.o : $(S_LIB_DIR)/%.c
	@ echo "[34m Assembling  libft object: [0m" $@
	@ $(CC) -o $@ $<

clean: 
	@ echo "[31m Deleted bin_lift. [0m"
	@-$(CLEAN)

fclean: clean
	@-$(CLEAN) $(NAME)
	@ echo "[31m Also deleted libft.a[0m"

re: fclean all
