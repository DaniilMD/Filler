#include "filler.h"

void		amnt_counter(t_param *param)
{
	int y;
	int x;

	param->mass_p_en.amnt = 0;
	param->mass_p_me.full_amnt = 0;
	y = -1;
	while (++y < param->size_y)
	{
		x = -1;
		while (++x < param->size_x)
		{
			if (param->map[y][x] == param->enemy_sym)
				param->mass_p_en.amnt++;
			if (param->map[y][x] == param->player_sym)
				param->mass_p_me.full_amnt++;
		}
	}
}

void		graphical_work(t_param *param)
{
	put_progress_bar(param);
	mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->mlx_par.img_ptr, 0, 0);
	if ((param->size_x == 17 && param->size_y == 15)
		|| (param->size_x == 40 && param->size_y == 24))
		jojo_fight(param);
	else
	{
		render(param);
		mlx_put_image_to_window(param->mlx_par.mlx_ptr,
			param->mlx_par.win_ptr, param->mlx_par.img_ptr, 0, 0);
	}
	make_title(param);
	put_strings(param);
	mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[1], 720, 90);
	mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[2], 850, 0);
	mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[9], 20, 50);
}

int			line_reader(t_param *param)
{
	char		*line;

	if (param->pause < 0)
	{
		mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[0], 200, 100);
		return (0);
	}
	if ((get_next_line(0, &line)) > 0)
	{
		read_map(param, line);
		get_token(param);
		free(line);
		if (param->changer == 0)
			amnt_counter(param);
		mlx_clear_window(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr);
		graphical_work(param);
		if (filler_player(param) == 0)
			return (0);
	}
	return (0);
}

int			init_param(t_param *param)
{
	char *line;

	param->map = NULL;
	param->token.token_map = NULL;
	if ((get_next_line(0, &line)) > 0)
	{
		param->player_sym =
			(ft_strncmp(line, "$$$ exec p1", 11) == 0) ? 'O' : 'X';
		param->enemy_sym =
			(ft_strncmp(line, "$$$ exec p1", 11) == 0) ? 'X' : 'O';
		free(line);
	}
	else
		return (0);
	param->turn = 0;
	param->changer = 0;
	param->pause = 1;
	param->mlx_par.mlx_ptr = mlx_init();
	param->mlx_par.win_ptr = mlx_new_window(param->mlx_par.mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT + 300, "Eto moe okno");
	param->mlx_par.img_ptr = mlx_new_image(param->mlx_par.mlx_ptr,
		WINDOW_WIDTH, WINDOW_HEIGHT + 300);
	param->mlx_par.mlx_data_addr = mlx_get_data_addr(param->mlx_par.img_ptr,
		&param->mlx_par.bpp, &param->mlx_par.size_line, &param->mlx_par.endian);
	return (1);
}

int			main(void)
{
	char	*line;
	t_param	param;

	if (init_param(&param) == 0)
		return (0);
	create_images(&param);
	if (check_images(&param) == 0)
		return (0);
	if (get_next_line(0, &line) == 0)
		return (0);
	read_map(&param, line);
	get_token(&param);
	free(line);
	amnt_counter(&param);
	graphical_work(&param);
	if (filler_player(&param) == 0)
		return (0);
	mlx_loop_hook(param.mlx_par.mlx_ptr, &line_reader, &param);
	mlx_hook(param.mlx_par.win_ptr, 2, 0, &key_press_down, (void*)&param);
	mlx_loop(param.mlx_par.mlx_ptr);
	return (0);
}
