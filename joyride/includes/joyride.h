/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joyride.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:54:01 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:21:21 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOYRIDE_H
# define JOYRIDE_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGHT 720
# define WIDTH 1280
# define SPRITE 192
# define NUM_SPRITE 64
# define COIN_SPRITE 128
# define X_POS 256
# define MIN_POS 528
# define MAX_POS 0
# define FALSE 0
# define TRUE 1

typedef struct s_pos
{
	double	gb_x[2];
	int		gb_bool[2];
	double	bb_x;
	int		bb_bool;
	double	pt_x[2];
	double	pt_y[2];
	int		pt_bool[2];
	double	bt_x[2];
	double	bt_y[2];
	int		bt_bool[2];
	double	tt_x;
	double	tt_y;
	int		tt_bool;
}	t_pos;

typedef struct s_vars
{
	int				trtl_ofst;
	unsigned char	level;
	unsigned int	i;
	long double		bg;
	long double		move;
	double			move_counter;
}	t_vars;

typedef struct s_time
{
	uint64_t	created_at;
	uint64_t	updated_at;
}	t_time;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	short	y_pos;
	int		mov_flag;
	double	acel;
	int		acel_flag;
	int		old_acel;
	int		alive_flag;
	int		coins;
	int		level;
	double	score;
	int		scr_ofst;
	int		best_score;
	int		sign[2];
	t_img	render;
	t_img	bg;
	t_img	fall;
	t_img	death;
	t_img	game_over;
	t_img	bullet;
	t_img	gomba[2];
	t_img	plnt[2];
	t_img	turtle[2];
	t_img	bomb[2];
	t_img	walk[4];
	t_img	fly[4];
	t_img	num[20];
	t_img	text[2];
}	t_data;

// Initial Init
t_pos	*pos(void);
t_vars	*counters(void);
void	ft_init_pos(void);
int		ft_mlx_init(t_data *prog);
void	ft_init_vars(t_data *prog);

// Render
int		ft_render(t_data *prog);
void	mario_movement(t_data *prog);
void	render_mario(t_data *prog, int i);
void	render_enemies(t_data *prog, int i);

// Enemy Spawn
void	spawn_bomb(t_data *prog, int i);
void	spawn_plant(t_data *prog, int i);
void	spawn_goomba(t_data *prog, int i);
void	spawn_bullet(t_data *prog, int i);
void	spawn_turtle(t_data *prog, int i, int old_i);

// Keys
int		handle_keypress(int keysym, t_data *prog);
int		handle_keyrelease(int keysym, t_data *prog);

// Exit and Free
int		ft_close(t_data *prog);
void	destroy_single_img(t_data *prog);
void	destroy_multiple_img(t_data *prog);
void	free_images(t_data *prog, t_img *img, int x);

// Reset
void	mini_reset_bullet(void);
void	reset_state(t_data *prog);

// Score Game
void	set_score(t_data *prog, int i);
void	put_score_to_img(t_data *prog);
void	ft_printnbr(t_data *prog, unsigned long num, int y, int flag);
void	digit_to_screen(t_data *prog, unsigned long num, int y, int flag);

// Score Vars
int		ft_min(int x, int y);
void	set_vars(t_data *prog);

// Score IO
void	init_score(t_data *prog);
void	save_score(t_data *prog);
void	ft_putnbr_fd(unsigned long num, int fd);

// Img Init 1
int		num_imgs(t_data *prog);
int		enemy_imgs(t_data *prog);
int		mario_imgs(t_data *prog);
int		ft_init_images(t_data *prog);

// Img Init 2
int		load_bg(t_data *prog, t_img *img, char *str);
int		load_nums(t_data *prog, t_img *img, char *str);
int		load_sprites(t_data *prog, t_img *img, char *str);

// Img Utils
int		getcolor(t_img *img, int x, int y);
void	put_img(t_img *dst, t_img *src, int x, int y);
void	img_pixel_put(t_img *img, int x, int y, int color);
void	mario_img_to_img(t_data *prog, t_img *src, int x, int y);
double	intrpl(double num, double new_min, double new_max, double old_max);

// Fps
int		update(void);
t_time	*time_vars(void);

// Memset
void	*ft_memset(void *s, int c, size_t n);

#endif