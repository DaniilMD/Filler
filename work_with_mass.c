#include "filler.h"

void	init_mass(t_param *param)
{
	param->mass_p_en.x_mass = 0;
	param->mass_p_en.x_cent_m = 0;
	param->mass_p_en.y_mass = 0;
	param->mass_p_en.y_cent_m = 0;
	param->mass_p_en.amnt = 0;
	param->mass_p_me.x_mass = 0;
	param->mass_p_me.x_cent_m = 0;
	param->mass_p_me.y_mass = 0;
	param->mass_p_me.y_cent_m = 0;
	param->mass_p_me.full_amnt = 0;
}

void	get_mass_center_enemy_and_me(t_param *param)
{
	int y;
	int x;

	init_mass(param);
	y = -1;
	while (++y < param->size_y)
	{
		x = -1;
		while (++x < param->size_x)
		{
			if (param->map[y][x] == param->enemy_sym)
			{
				param->mass_p_en.y_mass += y;
				param->mass_p_en.x_mass += x;
				param->mass_p_en.amnt++;
			}
			if (param->map[y][x] == param->player_sym)
			{
				param->mass_p_me.y_mass += y;
				param->mass_p_me.x_mass += x;
				param->mass_p_me.full_amnt++;
			}
		}
	}
	count_x_y_cent_m_me_en(param);
}

void	count_x_y_cent_m_me_en(t_param *param)
{
	param->mass_p_en.x_cent_m = param->mass_p_en.x_mass / param->mass_p_en.amnt;
	param->mass_p_en.y_cent_m = param->mass_p_en.y_mass / param->mass_p_en.amnt;
	param->mass_p_me.x_cent_m = param->mass_p_me.x_mass
		/ param->mass_p_me.full_amnt;
	param->mass_p_me.y_cent_m = param->mass_p_me.y_mass
		/ param->mass_p_me.full_amnt;
}

void	get_mass_cent_token(t_param *param, int y, int x)
{
	int	token_x;
	int	token_y;

	param->mass_p_me.y_mass_tkn = 0;
	param->mass_p_me.x_mass_tkn = 0;
	param->mass_p_me.amnt_tkn = 0;
	token_y = -1;
	while (++token_y < param->token.token_s_y)
	{
		token_x = -1;
		while (++token_x < param->token.token_s_x)
		{
			if (param->token.token_map[token_y][token_x] == '*')
			{
				param->mass_p_me.y_mass_tkn += y + token_y;
				param->mass_p_me.x_mass_tkn += x + token_x;
				param->mass_p_me.amnt_tkn++;
			}
		}
	}
	param->mass_p_me.y_cent_m_tkn = param->mass_p_me.y_mass_tkn
		/ param->mass_p_me.amnt_tkn;
	param->mass_p_me.x_cent_m_tkn = param->mass_p_me.x_mass_tkn
		/ param->mass_p_me.amnt_tkn;
}

double	get_mass_dist_who(t_param *param, char who)
{
	double	x_dist;
	double	y_dist;

	if (who == 'M')
	{
		x_dist = (param->mass_p_me.x_cent_m_tkn - param->mass_p_me.x_cent_m);
		y_dist = (param->mass_p_me.y_cent_m_tkn - param->mass_p_me.y_cent_m);
		return (x_dist * x_dist + y_dist * y_dist);
	}
	else if (who == 'E')
	{
		x_dist = (param->mass_p_me.x_cent_m_tkn - param->mass_p_en.x_cent_m);
		y_dist = (param->mass_p_me.y_cent_m_tkn - param->mass_p_en.y_cent_m);
		return (x_dist * x_dist + y_dist * y_dist);
	}
	else
		return (0);
}
