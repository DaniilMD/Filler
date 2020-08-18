#include "filler.h"

int			try_conclusion(t_param *param, int above_cnt, int x, int y)
{
	if (above_cnt > 1)
		return (0);
	if (above_cnt == 0)
		return (0);
	param->coord_to_put_x = x;
	param->coord_to_put_y = y;
	return (1);
}

int			try_it_out(t_param *param, int y, int x)
{
	int	token_x;
	int	token_y;
	int	above_cnt;

	above_cnt = 0;
	token_y = -1;
	while (++token_y < param->token.token_s_y)
	{
		token_x = -1;
		while (++token_x < param->token.token_s_x)
		{
			if (((param->token.token_map[token_y][token_x] == '*')
			&& (y + token_y > param->size_y - 1)) ||
				(((param->token.token_map[token_y][token_x] == '*')
			&& (x + token_x > param->size_x - 1))) ||
				(((param->token.token_map[token_y][token_x] == '*')
			&& ((param->map[y + token_y][x + token_x] == param->enemy_sym)))))
				return (0);
			if ((param->token.token_map[token_y][token_x] == '*')
			&& ((param->map[y + token_y][x + token_x] == param->player_sym)))
				above_cnt++;
		}
	}
	return (try_conclusion(param, above_cnt, x, y));
}

int			map_filler(t_param *param)
{
	if (param->turn == 0)
	{
		look_for_start_elems(param);
		get_runner_params(param);
		starter_runner_params(param);
		param->turn = 1;
	}
	if (param->changer != 0)
		return (mass_user(param));
	else
		return (order_user(param));
}

int			filler_player(t_param *param)
{
	if (map_filler(param) == 1)
	{
		ft_putnbr(param->coord_to_put_y);
		ft_putchar(' ');
		ft_putnbr(param->coord_to_put_x);
		ft_putchar('\n');
		return (1);
	}
	else
	{
		ft_putnbr(-1);
		ft_putchar(' ');
		ft_putnbr(-1);
		ft_putchar('\n');
		return (0);
	}
}
