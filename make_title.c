#include "filler.h"

void		make_title(t_param *param)
{
	put_title_purple(param);
	put_title_yellow(param);
	put_title_in(param);
}

void		make_square(t_param *param, int size, int start_x, int start_y)
{
	int				x;
	int				y;

	y = start_y;
	while (y < start_y + size - 2)
	{
		x = start_x;
		while (x < start_x + size - 2)
		{
			mlx_pixel_put(param->mlx_par.mlx_ptr,
			param->mlx_par.win_ptr, x, y, param->sqr_colour);
			x++;
		}
		y++;
	}
}

void		put_title_in(t_param *param)
{
	param->sqr_colour = 0x7F00FF;
	make_square(param, 15, 360, 90);
	make_square(param, 15, 360, 105);
	make_square(param, 15, 390, 60);
	make_square(param, 15, 390, 75);
	make_square(param, 15, 390, 90);
	make_square(param, 15, 390, 105);
	make_square(param, 15, 435, 60);
	make_square(param, 15, 435, 75);
	make_square(param, 15, 435, 90);
	make_square(param, 15, 435, 105);
	param->sqr_colour = 0xD2B400;
	make_square(param, 15, 360, 60);
	make_square(param, 15, 405, 75);
	make_square(param, 15, 420, 90);
}

void		put_title_purple(t_param *param)
{
	param->sqr_colour = 0x7F00FF;
	make_square(param, 15, 285, 130);
	make_square(param, 15, 285, 145);
	make_square(param, 15, 285, 160);
	make_square(param, 15, 285, 175);
	make_square(param, 15, 285, 190);
	make_square(param, 15, 345, 160);
	make_square(param, 15, 345, 175);
	make_square(param, 15, 345, 190);
	make_square(param, 15, 375, 160);
	make_square(param, 15, 375, 175);
	make_square(param, 15, 375, 190);
	make_square(param, 15, 405, 130);
	make_square(param, 15, 405, 145);
	make_square(param, 15, 405, 160);
	make_square(param, 15, 435, 130);
	make_square(param, 15, 435, 145);
	make_square(param, 15, 435, 160);
	make_square(param, 15, 435, 175);
	make_square(param, 15, 435, 190);
	make_square(param, 15, 495, 130);
	make_square(param, 15, 495, 145);
	make_square(param, 15, 495, 160);
	make_square(param, 15, 495, 175);
	make_square(param, 15, 495, 190);
}

void		put_title_yellow(t_param *param)
{
	param->sqr_colour = 0xD2B400;
	make_square(param, 15, 300, 130);
	make_square(param, 15, 315, 130);
	make_square(param, 15, 300, 160);
	make_square(param, 15, 315, 160);
	make_square(param, 15, 345, 130);
	make_square(param, 15, 375, 130);
	make_square(param, 15, 375, 145);
	make_square(param, 15, 405, 175);
	make_square(param, 15, 405, 190);
	make_square(param, 15, 450, 130);
	make_square(param, 15, 465, 130);
	make_square(param, 15, 450, 160);
	make_square(param, 15, 465, 160);
	make_square(param, 15, 450, 190);
	make_square(param, 15, 465, 190);
	make_square(param, 15, 510, 130);
	make_square(param, 15, 525, 130);
	make_square(param, 15, 525, 145);
	make_square(param, 15, 525, 160);
	make_square(param, 15, 510, 160);
	make_square(param, 15, 510, 175);
	make_square(param, 15, 525, 190);
}
