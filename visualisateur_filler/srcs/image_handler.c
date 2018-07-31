#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include "../includes/filler.h"
#include "../libft/libft.h"

t_mlx	set_get_mlx(t_mlx *mlx)
{
	static t_mlx mlx_linker;

	if (mlx)
		mlx_linker = *mlx;
	return (mlx_linker);
}

int		loop_filler(int necessary)
{
	(void)necessary;
	board_img_handler();
	return (1);
}

static	t_mlx	my_mlx_init(void)
{
	t_mlx	mlx;
	int		bpp;
	int		endian;
	int		size_line;

	if (!(mlx.mlx = mlx_init()))
		ft_myexit("malloc error");
	if (!(mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "Filler")))
		ft_myexit("malloc error");
	if (!(mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE)))
		ft_myexit("malloc error");
	if (!(mlx.screen_data = (int*)mlx_get_data_addr(mlx.image,
					&bpp, &size_line, &endian)))
		ft_myexit("malloc error");
	set_get_mlx(&mlx);
	board_img_handler();
	return (mlx);
}

void	find_winner(t_filler *game_settings, char *buf)
{
	int				p1_score;
	int				p2_score;

	p1_score = ft_atoi(&buf[10]);
	get_next_line(0, &buf);
	p2_score = ft_atoi(&buf[10]);
	if (p1_score > p2_score)
	{
		game_settings->game_over = P1 + 1;
		game_settings->end_score = p1_score - p2_score;
	}
	else
	{
		game_settings->game_over = P2 + 1;
		game_settings->end_score = p2_score - p1_score;
	}
	return ;
}

void	pass_pieces_or_find_winner(t_filler *game_settings)
{
	char			*buf;

	buf = NULL;
	while (get_next_line(0, &buf) && !(ft_strstr(buf, "Plateau")))
	{
		if (ft_strstr(buf, "fin"))
			find_winner(game_settings, buf);
	}
	get_next_line(0, &buf);
	if (ft_strstr(buf, "fin"))
		find_winner(game_settings, buf);
}

void	mlx_put_winner(t_mlx mlx, t_filler gs)
{
	char	winner[1024];
	char	*result;

	ft_memset(winner, 0, 1024);
	result = NULL;
	result = ft_itoa(gs.end_score);
	if (gs.game_over == P1 + 1)
		ft_memcpy(winner, gs.p1_info + 30, ft_strlen(gs.p1_info + 30)); 
	if (gs.game_over == P2 + 1)
		ft_memcpy(winner, gs.p2_info + 30, ft_strlen(gs.p2_info + 30)); 
	ft_memcpy(winner + ft_strlen(winner), " won by : ", ft_strlen(" won by : ")); 
	ft_memcpy(winner + ft_strlen(winner), result, ft_strlen(result));
	ft_memdel((void**)&result);
	mlx_string_put(mlx.mlx, mlx.win, (X_SIZE - (ft_strlen(winner) * 10)) / 2, 32, 0xff0000, winner);
}

void	board_img_handler(void)
{
	t_mlx			mlx;
	static t_sqrt	**board = NULL;
	static t_filler	game_settings;
	static int		first = 1;

	mlx = set_get_mlx(NULL);
	if (first)
	{
		game_settings = get_game_settings();
		if (!(board = board_malloc(game_settings)))
			return ;
		first = 0;
	}
	pass_pieces_or_find_winner(&game_settings);
	if (!game_settings.game_over)
	{
		board = board_init(board, &game_settings);
		board_update(board, &game_settings);
	}
	display_pieces(game_settings, board, &(mlx.screen_data)); 
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	put_player_info(mlx, game_settings, P1);
	put_player_info(mlx, game_settings, P2);
	if (game_settings.game_over)
		mlx_put_winner(mlx, game_settings);
}

int		draw(void)
{
	static	t_mlx	mlx;
	static	int		initalize = 0;

	if (!initalize)
	{
		mlx = my_mlx_init();
		initalize = 1;
	}
	mlx_loop_hook(mlx.mlx, loop_filler, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
