#include "filler.h"

void		put_strings(t_param *param)
{
	if (param->player_sym == 'O')
	{
		mlx_string_put(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr,
			500, 40, 0x7F00FF, "openelop.filler plays as Jotaro");
		mlx_string_put(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr,
			500, 100, 0xd2b400, "ENEMY.filler plays as Dio ");
	}
	else
	{
		mlx_string_put(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr,
			500, 40, 0x7F00FF, "ENEMY.filler plays as Jotaro");
		mlx_string_put(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr,
			500, 100, 0xd2b400, "openelop.filler plays as Dio ");
	}
}

void		put_progress_bar(t_param *param)
{
	int	x;
	int	y;
	int	all;
	int	left_part;

	all = param->mass_p_me.full_amnt + param->mass_p_en.amnt;
	y = 249;
	while (++y < 300)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			param->mlx_par.im_count = x * (param->mlx_par.bpp) / 8
		+ y * (param->mlx_par.size_line);
			if (param->player_sym == 'O')
				left_part = param->mass_p_me.full_amnt * WINDOW_WIDTH;
			else
				left_part = param->mass_p_en.amnt * WINDOW_WIDTH;
			if (all * x < left_part)
				set_colour(param, 125, 0, 255);
			else
				set_colour(param, 210, 180, 0);
		}
	}
}

void		create_images(t_param *param)
{
	int width;
	int	height;

	width = 1;
	height = 1;
	param->imgs[0] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/to_be_c.xpm", &width, &height);
	param->imgs[1] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/Dio.xpm", &width, &height);
	param->imgs[2] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/Jotaro.xpm", &width, &height);
	param->imgs[3] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/starpl 10x10.xpm", &width, &height);
	param->imgs[4] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/the world 10x10.xpm", &width, &height);
	param->imgs[5] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/starpl 25x25.xpm", &width, &height);
	param->imgs[6] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/the world 25x25.xpm", &width, &height);
	param->imgs[7] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/starpl 58x58.xpm", &width, &height);
	param->imgs[8] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/the world 58x58.xpm", &width, &height);
	param->imgs[9] = mlx_xpm_file_to_image(param->mlx_par.mlx_ptr,
		"../xpms/jojobiz.xpm", &width, &height);
}

int			check_images(t_param *param)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!param->imgs[i])
			return (0);
		i++;
	}
	return (1);
}
