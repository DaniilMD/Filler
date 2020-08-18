#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <mlx.h>
# include <pthread.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define THREADS_NUM 10

typedef struct	s_mlx_par
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*mlx_data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			im_count;
}				t_mlx_par;

typedef struct	s_token
{
	int			token_s_x;
	int			token_s_y;
	char		**token_map;
}				t_token;

typedef struct	s_runner
{
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
	char		ord_pr;
	int			top_wall;
	int			bot_wall;
	int			left_wall;
	int			right_wall;
}				t_runner;

typedef struct	s_pos
{
	int			i_x;
	int			i_y;
	int			enemy_x;
	int			enemy_y;
}				t_pos;

typedef struct	s_mass_p_en
{
	int			amnt;
	int			x_mass;
	int			x_cent_m;
	int			y_mass;
	int			y_cent_m;
}				t_mass_p_en;

typedef struct	s_mass_p_me
{
	int			amnt_tkn;
	int			x_mass_tkn;
	double		x_cent_m_tkn;
	int			y_mass_tkn;
	double		y_cent_m_tkn;
	int			x_mass;
	double		x_cent_m;
	int			y_mass;
	double		y_cent_m;
	int			full_amnt;
}				t_mass_p_me;

typedef struct	s_param
{
	char		player_sym;
	char		enemy_sym;
	int			size_x;
	int			size_y;
	char		**map;
	t_token		token;
	int			coord_to_put_x;
	int			coord_to_put_y;
	int			turn;
	t_runner	runner;
	int			closest_m_x;
	int			closest_m_y;
	double		closest_mass;
	t_pos		psns;
	t_mass_p_en	mass_p_en;
	t_mass_p_me	mass_p_me;
	int			changer;
	t_mlx_par	mlx_par;
	int			pause;
	void		*imgs[10];
	int			sqr_colour;
}				t_param;

typedef struct	s_for_threads
{
	t_param		param;
	int			thread_num;
	int			*iters;
}				t_for_threads;

/*
** main.c
*/

void			amnt_counter(t_param *param);
int				try_it_out(t_param *param, int y, int x);
int				map_filler(t_param *param);

/*
** play_filler.c
*/

int				try_conclusion(t_param *param, int above_cnt, int x, int y);
int				try_it_out(t_param *param, int y, int x);
int				map_filler(t_param *param);
int				filler_player(t_param *param);

/*
** get_map_and_token.c
*/

void			free_map(t_param *param);
void			create_map(t_param *param, char *curr_line);
void			read_map(t_param *param, char *curr_line);
void			get_token(t_param *param);

/*
** work_with_walls.c
*/

void			get_info_about_walls(t_param *param);
void			reach_a_wall(t_param *param);
void			reach_some_walls(t_param *param);

/*
** get_started.c
*/

void			look_for_start_elems(t_param *param);
void			get_runner_params(t_param *param);
void			starter_runner_params(t_param *param);

/*
** work_with_mass.c
*/

void			init_mass(t_param *param);
void			get_mass_center_enemy_and_me(t_param *param);
void			count_x_y_cent_m_me_en(t_param *param);
void			get_mass_cent_token(t_param *param, int y, int x);
double			get_mass_dist_who(t_param *param, char who);

/*
** main_algs.c
*/

int				mass_user(t_param *param);
void			mass_swithcer(t_param *param, int y, int x);
int				order_user(t_param *param);
int				order_main_y(t_param *param);
int				order_main_x(t_param *param);

/*
** graphics.c
*/

void			render(t_param *param);
void			set_colour(t_param *param, int r, int g, int b);
void			*fight_drawer(void *thr_param_void);
void			put_filler_square(t_param *param, int x_curr, int y_curr);
void			jojo_fight(t_param *param);

/*
** extra_graphics.c
*/

void			put_progress_bar(t_param *param);
void			put_strings(t_param *param);
void			create_images(t_param *param);
int				check_images(t_param *param);

/*
** make_title.c.c
*/

void			make_title(t_param *param);
void			make_square(t_param *param, int size, int start_x, int start_y);
void			put_title_in(t_param *param);
void			put_title_purple(t_param *param);
void			put_title_yellow(t_param *param);

/*
** event_work.c
*/

int				key_press_down(int keycode, void *param_void);
int				pause_filler(t_param *param);
void			close_window(t_param *param);

#endif
