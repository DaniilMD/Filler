#include "filler.h"

void		render(t_param *param)
{
	int				i;
	t_for_threads	wtf[THREADS_NUM];
	pthread_t		threads[THREADS_NUM];

	i = 0;
	while (i < THREADS_NUM)
	{
		wtf[i].param = *param;
		wtf[i].thread_num = i;
		i++;
	}
	i = 0;
	while (i < THREADS_NUM)
	{
		pthread_create(&(threads[i]), NULL, fight_drawer, &wtf[i]);
		i++;
	}
	i = 0;
	while (i < THREADS_NUM)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void		set_colour(t_param *param, int r, int g, int b)
{
	param->mlx_par.mlx_data_addr[param->mlx_par.im_count] = b;
	param->mlx_par.mlx_data_addr[param->mlx_par.im_count + 1] = g;
	param->mlx_par.mlx_data_addr[param->mlx_par.im_count + 2] = r;
}

void		put_filler_square(t_param *param, int x_curr, int y_curr)
{
	int				x;
	int				y;

	y = 0;
	while (y * param->size_y < WINDOW_HEIGHT - param->size_y * 2)
	{
		x = 0;
		while (x * param->size_x < WINDOW_WIDTH - param->size_x * 2)
		{
			param->mlx_par.im_count = ((x_curr *
	(WINDOW_WIDTH / param->size_x)) + x) * (param->mlx_par.bpp) / 8
	+ ((y_curr * (WINDOW_HEIGHT / param->size_y))
			+ y + 300) * (param->mlx_par.size_line);
			if (param->map[y_curr][x_curr] == '.')
				set_colour(param, 210, 105, 30);
			else if (param->map[y_curr][x_curr] == 'O')
				set_colour(param, 125, 0, 255);
			else if (param->map[y_curr][x_curr] == 'X')
				set_colour(param, 210, 180, 0);
			x++;
		}
		y++;
	}
}

void		*fight_drawer(void *thr_param_void)
{
	int				x;
	int				y;
	t_for_threads	*thr_param;

	thr_param = (t_for_threads *)thr_param_void;
	y = thr_param->thread_num * (thr_param->param.size_y / THREADS_NUM);
	while (y < (thr_param->thread_num + 1)
		* (thr_param->param.size_y / THREADS_NUM))
	{
		x = 0;
		while (x < thr_param->param.size_x)
		{
			put_filler_square(&(thr_param->param), x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		jojo_fight(t_param *param)
{
	int		x;
	int		y;

	y = -1;
	while (++y < param->size_y)
	{
		x = -1;
		while (++x < param->size_x)
		{
			if (param->map[y][x] == 'O' && param->size_x == 40)
				mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[5], x * 25, y * 42 + 300);
			else if (param->map[y][x] == 'X' && param->size_x == 40)
				mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[6], x * 25, y * 42 + 300);
			else if (param->map[y][x] == 'O' && param->size_x == 17)
				mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[7], x * 58, y * 67 + 300);
			else if (param->map[y][x] == 'X' && param->size_x == 17)
				mlx_put_image_to_window(param->mlx_par.mlx_ptr,
		param->mlx_par.win_ptr, param->imgs[8], x * 58, y * 67 + 300);
		}
	}
}
