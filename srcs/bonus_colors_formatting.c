#include "../includes/libft.h"
#include "../includes/printf.h"

void	help(void)
{
	ft_printf("Available formatting options for \
[[yellow]][[underline]][[bold]][[italic]]lazrossi's fr_printf\
[[end]] are :\n [[red]]red,\n [[green]]green,\n [[yellow]]yellow[[end]],\
	\n [[blue]]blue,\n [[magenta]]magenta,\n [[cyan]]cyan,\n [[white]]white,\
	\n [[end]][[underline]]underline[[end]],\
	\n [[bold]]bold,\n [[end]][[italic]]italic,\n [[end]][[blink]]blink,\
	\n [[end]][[background]]setting [[underline]]background[[end]] color\
	\n [[swapp]][[underline]][[italic]]swapp[[end]][[swapp]]ing foreground\
 and background\
colors.[[end]]\n Simply [[italic]]input[[end]] those options in your ft_printf\
 string in the following fashion :\n[[end]] [[bold]][[option]]\
	\n[[red]][[bold]][[underline]]Caution :[[end]] some escape sequences may\
 not be supported by your terminal.");
}

char		*continue_font_formatting(char *format, t_printf *argument)
{
	if (!(ft_strncmp(format, "[[background]]", 14)))
	{
		argument->to_store = BCK;
		store_print_handler(argument, 1, 1, 5);
		format += 14;
		return (terminal_formatting(format, argument));
	}
	else if (!(ft_strncmp(format, "[[underline]]", 13)))
	{
		argument->to_store = UND;
		format += 13;
	}
	else if (!(ft_strncmp(format, "[[swapp]]", 9)))
	{
		argument->to_store = SWP;
		format += 9;
	}
	else
		return (format);
	store_print_handler(argument, 1, 1, 4);
	return (terminal_formatting(format, argument));
}

char		*font_formatting(char *format, t_printf *argument)
{
	if (!(ft_strncmp(format, "[[bold]]", 8)))
	{
		argument->to_store = BLD;
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[end]]", 7)))
	{
		argument->to_store = RESET;
		format += 7;
	}
	else if (!(ft_strncmp(format, "[[italic]]", 10)))
	{
		argument->to_store = ITA;
		format += 10;
	}
	else if (!(ft_strncmp(format, "[[blink]]", 9)))
	{
		argument->to_store = BLK;
		format += 9;
	}
	else
		return (format = continue_font_formatting(format, argument));
	store_print_handler(argument, 1, 1, 4);
	return (terminal_formatting(format, argument));
}

char		*continue_color_formatting(char *format, t_printf *argument)
{
	if (!(ft_strncmp(format, "[[blue]]", 8)))
	{
		argument->to_store = "\033[34m";
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[magenta]]", 11)))
	{
		argument->to_store = MAG;
		format += 11;
	}
	else if (!(ft_strncmp(format, "[[cyan]]", 8)))
	{
		argument->to_store = CYN;
		format += 8;
	}
	else if (!(ft_strncmp(format, "[[white]]", 9)))
	{
		argument->to_store = WHT;
		format += 9;
	}
	else
		return (format = font_formatting(format, argument));
	store_print_handler(argument, 1, 1, 5);
	return (terminal_formatting(format, argument));
}

char		*terminal_formatting(char *format, t_printf *argument)
{
	if (!(ft_strncmp(format, "[[red]]", 7)))
	{
		argument->to_store = RED;
		format += 7;
	}
	else if (!(ft_strncmp(format, "[[green]]", 9)))
	{
		argument->to_store = GRN;
		format += 9;
	}
	else if (!(ft_strncmp(format, "[[yellow]]", 10)))
	{
		argument->to_store = YEL;
		format += 10;
	}
	else if (!(ft_strncmp(format, "[[help?]]", 9)))
	{
		help();
		return (NULL);
	}
	else 
		return (format = continue_color_formatting(format, argument));
	store_print_handler(argument, 1, 1, 5);
	return (terminal_formatting(format, argument));
}
