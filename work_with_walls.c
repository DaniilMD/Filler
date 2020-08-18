#include "filler.h"

void	get_info_about_walls(t_param *param)
{
	int	i;

	i = 0;
	param->runner.top_wall = 0;
	param->runner.bot_wall = 0;
	param->runner.left_wall = 0;
	param->runner.right_wall = 0;
	while (i < param->size_x)
	{
		if (param->map[0][i] == param->player_sym)
			param->runner.top_wall = 1;
		if (param->map[param->size_y - 1][i] == param->player_sym)
			param->runner.bot_wall = 1;
		i++;
	}
	i = 0;
	while (i < param->size_y)
	{
		if (param->map[i][0] == param->player_sym)
			param->runner.left_wall = 1;
		if (param->map[i][param->size_x - 1] == param->player_sym)
			param->runner.right_wall = 1;
		i++;
	}
	reach_a_wall(param);
}

void	reach_a_wall(t_param *param)
{
	if (param->runner.top_wall == 1 && param->runner.bot_wall == 0)
	{
		param->runner.y_start = param->size_y;
		param->runner.y_end = 0;
	}
	if (param->runner.top_wall == 0 && param->runner.bot_wall == 1)
	{
		param->runner.y_start = 0;
		param->runner.y_end = param->size_y;
	}
	if (param->runner.left_wall == 1 && param->runner.right_wall == 0)
	{
		param->runner.x_start = param->size_x;
		param->runner.x_end = 0;
	}
	if (param->runner.left_wall == 0 && param->runner.right_wall == 1)
	{
		param->runner.x_start = 0;
		param->runner.x_end = param->size_x;
	}
	reach_some_walls(param);
}

void	reach_some_walls(t_param *param)
{
	if (param->runner.left_wall == 1 && param->runner.right_wall == 1)
	{
		get_runner_params(param);
		param->changer = 1;
	}
	if (param->runner.top_wall == 1 && param->runner.bot_wall == 1)
	{
		get_runner_params(param);
		param->changer = 1;
	}
}
