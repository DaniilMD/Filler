#include "filler.h"

void		look_for_start_elems(t_param *param)
{
	int y;
	int x;

	y = 0;
	while (y < param->size_y)
	{
		x = 0;
		while (x < param->size_x)
		{
			if (param->map[y][x] == param->player_sym)
			{
				param->psns.i_x = x;
				param->psns.i_y = y;
			}
			if (param->map[y][x] == param->enemy_sym)
			{
				param->psns.enemy_x = x;
				param->psns.enemy_y = y;
			}
			x++;
		}
		y++;
	}
}

void		get_runner_params(t_param *param)
{
	if (param->psns.i_x < param->psns.enemy_x)
	{
		param->runner.x_start = param->size_x;
		param->runner.x_end = 0;
	}
	else
	{
		param->runner.x_start = 0;
		param->runner.x_end = param->size_x;
	}
	if (param->psns.i_y < param->psns.enemy_y)
	{
		param->runner.y_start = param->size_y;
		param->runner.y_end = 0;
	}
	else
	{
		param->runner.y_start = 0;
		param->runner.y_end = param->size_y;
	}
}

void		starter_runner_params(t_param *param)
{
	int		w;
	int		h;

	w = param->psns.enemy_x > param->psns.i_x;
	if (w < 0)
		w *= -1;
	h = param->psns.enemy_y > param->psns.i_y;
	if (h < 0)
		h *= -1;
	if (h < w)
		param->runner.ord_pr = 'x';
	else
		param->runner.ord_pr = 'y';
}
