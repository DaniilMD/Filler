#include "filler.h"

int		mass_user(t_param *param)
{
	int		y;
	int		x;

	get_mass_center_enemy_and_me(param);
	param->closest_mass = 99999999;
	y = 0;
	while (y < param->size_y)
	{
		x = 0;
		while (x < param->size_x)
		{
			mass_swithcer(param, y, x);
			x++;
		}
		y++;
	}
	if (param->closest_mass == 99999999)
		return (0);
	param->coord_to_put_x = param->closest_m_x;
	param->coord_to_put_y = param->closest_m_y;
	return (1);
}

void	mass_swithcer(t_param *param, int y, int x)
{
	double	mass_dist_en;
	double	mass_dist_me;
	double	dist_ref;

	if (try_it_out(param, y, x) == 1)
	{
		get_mass_cent_token(param, y, x);
		mass_dist_en = get_mass_dist_who(param, 'E');
		mass_dist_me = get_mass_dist_who(param, 'M');
		if (mass_dist_me == 0)
			dist_ref = 999999;
		else
		{
			dist_ref = mass_dist_en / mass_dist_me - 0.5;
			if (dist_ref < 0)
				dist_ref *= -1;
		}
		if (dist_ref < param->closest_mass)
		{
			param->closest_mass = dist_ref;
			param->closest_m_x = x;
			param->closest_m_y = y;
		}
	}
}

int		order_user(t_param *param)
{
	get_info_about_walls(param);
	if (param->runner.ord_pr == 'y')
		return (order_main_y(param));
	else
		return (order_main_x(param));
	return (0);
}

int		order_main_y(t_param *param)
{
	int x;
	int y;

	y = param->runner.y_start;
	while (y != param->runner.y_end)
	{
		x = param->runner.x_start;
		while (x != param->runner.x_end)
		{
			if (try_it_out(param, y, x) == 1)
				return (1);
			if (param->runner.x_end == 0)
				x--;
			else
				x++;
		}
		if (param->runner.y_end == 0)
			y--;
		else
			y++;
	}
	return (0);
}

int		order_main_x(t_param *param)
{
	int	x;
	int	y;

	x = param->runner.x_start;
	while (x != param->runner.x_end)
	{
		y = param->runner.y_start;
		while (y != param->runner.y_end)
		{
			if (try_it_out(param, y, x) == 1)
				return (1);
			if (param->runner.y_end == 0)
				y--;
			else
				y++;
		}
		if (param->runner.x_end == 0)
			x--;
		else
			x++;
	}
	return (0);
}
