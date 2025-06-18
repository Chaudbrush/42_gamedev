/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:03:13 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:42:57 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
# define PONG_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 1280
# define HEIGHT 720
# define BAR_HEIGHT 100
# define BAR_WIDTH 20
# define BALL_HEIGHT 16
# define BALL_WIDTH 16
# define MLX_ERROR 1
# define TRUE 1
# define FALSE 0
# define PAUSE -1

typedef struct s_utils
{
	int			offset_p1;
	int			offset_p2;
	int			offset_bar;
	double		ball_x;
	double		ball_y;
	double		old_y;
	int			start;
	int			ball_x_sign;
	int			ball_y_sign;
	int			score_p1;
	int			score_p2;
	int			p1_w;
	int			p1_s;
	int			p2_up;
	int			p2_down;
	double		x_speed;
	double		y_speed;
	int			sign[2];
	int			collision;
}				t_utils;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_utils		utils;
}				t_data;

int		ft_mlx_init(t_data *prog);
void	ft_init_data(t_data *prog);
int		handle_keypress(int keysym, t_data *prog);
int		handle_keyrelease(int keysym, t_data *prog);

int		close_all(t_data *prog);
int		ft_close_min(t_data *prog);
int		ft_close_half(t_data *prog);

void	pivot_p1(t_utils *utils);
void	pivot_p2(t_utils *utils);
int		check_movement(t_utils *utils);
void	check_colision(t_data *prog, t_utils *utils);
void	reset_game(t_data *prog, t_utils *utils, int x);

int		render_img(t_data *prog);
int		render_limit(t_img *img);
void	call_printers(t_data *prog);
int		render_background(t_img *img);
int		render_ball_mask(t_img *img, t_utils *utils);

int		paint_ball(int x, int y);
void	ball_movement(t_utils *utils);
int		render_ball(t_img *img, t_utils *util);
int		render_player1(t_img *img, t_utils util);
int		render_player2(t_img *img, t_utils util);

void	print_score(t_img *img, t_utils *utils);
int		score_p1(t_img *img, int digit, int x, int y);
int		score_p2(t_img *img, int digit, int x, int y);

void	print_zero(t_img *img, int offset_x, int offset_y);
void	print_one(t_img *img, int offset_x, int offset_y);
void	print_two(t_img *img, int offset_x, int offset_y);
void	print_three(t_img *img, int offset_x, int offset_y);
void	print_four(t_img *img, int offset_x, int offset_y);

void	print_five(t_img *img, int offset_x, int offset_y);
void	print_six(t_img *img, int offset_x, int offset_y);
void	print_seven(t_img *img, int offset_x, int offset_y);
void	print_eight(t_img *img, int offset_x, int offset_y);
void	print_nine(t_img *img, int offset_x, int offset_y);

double	min(double a, double b);
int		img_pixel_put(t_img *img, int x, int y, int color);
double	interpolation(double num, double new_min, \
						double new_max, double old_max);

#endif
