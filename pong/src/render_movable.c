/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:13:50 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

int	render_player1(t_img *img, t_utils utils)
{
	int	x;
	int	y;

	y = (HEIGHT / 2) - BAR_HEIGHT / 2;
	while (++y < (HEIGHT / 2) + BAR_HEIGHT / 2)
	{
		x = -1;
		while (++x < BAR_WIDTH)
			img_pixel_put(img, x + utils.offset_bar, y + \
						utils.offset_p1, 0xFFFFFF);
	}
	return (0);
}

int	render_player2(t_img *img, t_utils utils)
{
	int	x;
	int	y;

	y = (HEIGHT / 2) - BAR_HEIGHT / 2;
	while (++y < (HEIGHT / 2) + BAR_HEIGHT / 2)
	{
		x = -1;
		while (++x < BAR_WIDTH)
			img_pixel_put(img, x - utils.offset_bar - \
						BAR_WIDTH, y + utils.offset_p2, 0xFFFFFF);
	}
	return (0);
}

int	render_ball(t_img *img, t_utils *utils)
{
	int	x;
	int	y;

	y = (HEIGHT / 2) - 16;
	while (y < HEIGHT / 2 + 16)
	{
		x = (WIDTH / 2) - 16;
		while (x < WIDTH / 2 + 16)
		{
			if (paint_ball(x, y))
				img_pixel_put(img, x + utils->ball_x, y + \
						utils->ball_y, 0x000000);
			else
				img_pixel_put(img, x + utils->ball_x, y + \
						utils->ball_y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}

int	paint_ball(int x, int y)
{
	if (x < (WIDTH / 2) - 8 && y < (HEIGHT / 2) - 12)
		return (1);
	else if (x > (WIDTH / 2) + 7 && y < (HEIGHT / 2) - 12)
		return (1);
	else if (x < (WIDTH / 2) - 12 && y < (HEIGHT / 2) - 8)
		return (1);
	else if (x > (WIDTH / 2) + 11 && y < (HEIGHT / 2) - 8)
		return (1);
	else if (x < (WIDTH / 2) - 12 && y > (HEIGHT / 2) + 7)
		return (1);
	else if (x < (WIDTH / 2) - 8 && y > (HEIGHT / 2) + 11)
		return (1);
	else if (x > (WIDTH / 2) + 7 && y > (HEIGHT / 2) + 11)
		return (1);
	else if (x > (WIDTH / 2) + 11 && y > (HEIGHT / 2) + 7)
		return (1);
	return (0);
}

void	ball_movement(t_utils *utils)
{
	static int	collision;

	if (utils->collision == FALSE)
	{
		collision++;
		if (collision == 150)
		{
			collision = 0;
			utils->collision = TRUE;
		}
	}
	utils->old_y = utils->ball_y;
	utils->ball_x += utils->x_speed * utils->ball_x_sign;
	utils->ball_y += utils->y_speed * utils->ball_y_sign;
}
