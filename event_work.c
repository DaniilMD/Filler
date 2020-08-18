#include "filler.h"

int			key_press_down(int keycode, void *param_void)
{
	t_param			*param;

	param = (t_param *)param_void;
	if (keycode == 49)
		pause_filler(param);
	else if (keycode == 53)
		close_window(param);
	return (0);
}

int			pause_filler(t_param *param)
{
	param->pause *= -1;
	return (0);
}

void		close_window(t_param *param)
{
	mlx_clear_window(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr);
	mlx_destroy_image(param->mlx_par.mlx_ptr, param->mlx_par.img_ptr);
	mlx_destroy_window(param->mlx_par.mlx_ptr, param->mlx_par.win_ptr);
	free_char_starstar(param->token.token_map);
	free_char_starstar(param->map);
	(void)(param->token);
	(void)(param->runner);
	(void)(param->psns);
	(void)(param->mass_p_en);
	(void)(param->mass_p_me);
	(void)(param->mlx_par);
	(void)param;
	exit(0);
}
