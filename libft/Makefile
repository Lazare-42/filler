# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jboursal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 11:05:26 by jboursal          #+#    #+#              #
#    Updated: 2018/07/18 12:52:23 by lazrossi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRCS =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strctchr.c\
		ft_strtcchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_nn_strjoin.c\
		ft_strnjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_n_len.c\
		ft_power.c\
		ft_str_split_ptr.c\
		ft_strcount.c\
		ft_strcpy_c.c\
		ft_strwsplen.c\
		ft_isspace.c\
		ft_isblank.c\
		ft_isblank_or_n.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_abs.c\
		ft_strchrnul.c\
		ft_itoa_base.c\
		ft_utoa_base.c\
		ft_get_add.c\
		ft_utoa.c\
		ft_strndup.c\
		ft_strsubfree.c\
		ft_strjoinfree.c\
		ft_strjoinfree2.c\
		ft_exit_error.c\
		ft_multifree.c\
		get_next_line.c\
		ft_tabdel.c \

HEAD = ./

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c libft.h
	gcc $(FLAGS) -c $(SRCS) -I $(HEAD)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
