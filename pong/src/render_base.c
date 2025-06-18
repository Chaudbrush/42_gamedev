/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:13:50 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:28 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

int	render_img(t_data *prog)
{
	static int	time;

	if (prog->win == NULL)
		return (MLX_ERROR);
	check_colision(prog, &prog->utils);
	check_movement(&prog->utils);
	call_printers(prog);
	if (prog->utils.start == TRUE)
		ball_movement(&prog->utils);
	render_ball(&prog->img, &prog->utils);
	if (prog->utils.start == PAUSE)
	{
		time++;
		render_ball_mask(&prog->img, &prog->utils);
		if (time == 200)
		{
			time = 0;
			prog->utils.start = TRUE;
		}
	}
	mlx_put_image_to_window(prog->mlx, prog->win, prog->img.img, 0, 0);
	return (0);
}

void	call_printers(t_data *prog)
{
	render_background(&prog->img);
	render_limit(&prog->img);
	print_score(&prog->img, &prog->utils);
	render_player1(&prog->img, prog->utils);
	render_player2(&prog->img, prog->utils);
}

int	render_background(t_img *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			img_pixel_put(img, x, y, 0x000000);
	}
	return (0);
}

int	render_limit(t_img *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (x < 10 || x > WIDTH - 10 || y < 10 || y > HEIGHT - 10)
				img_pixel_put(img, x, y, 0xFFFFFF);
		}
	}
	return (0);
}

int	render_ball_mask(t_img *img, t_utils *utils)
{
	int	x;
	int	y;

	y = (HEIGHT / 2) - 16;
	while (y < HEIGHT / 2 + 16)
	{
		x = (WIDTH / 2) - 16;
		while (x < WIDTH / 2 + 16)
		{
			img_pixel_put(img, x + utils->ball_x, y + \
						utils->ball_y, 0x000000);
			x++;
		}
		y++;
	}
	return (0);
}
