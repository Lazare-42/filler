#include "./libft.h"

t_color_compound	ft_decompose_color(int color)
{
	struct s_color_compound c;
	c.red = (char)(color >> 16);
	c.green = (char)((color & 0x00ff00) >> 8);
	c.blue = (char)(color & 0x0000ff);
	return c;
}
