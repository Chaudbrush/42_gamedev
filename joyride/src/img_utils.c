/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:35:39 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 19:34:29 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	getcolor(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (color == 0x0F000000)
		return ;
	pixel = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	put_img(t_img *dst, t_img *src, int x, int y)
{
	int	i;
	int	j;

	j = -1;
	while (++j < src->h)
	{
		i = -1;
		while (++i < src->w)
		{
			img_pixel_put(dst, x + i, y + j, getcolor(src, i, j));
		}
	}
}

void	mario_img_to_img(t_data *prog, t_img *src, int x, int y)
{
	int	i;
	int	j;
	int	check;
	int	color;

	j = -1;
	while (++j < src->h)
	{
		i = -1;
		while (++i < src->w)
		{
			color = getcolor(src, i, j);
			check = color & 0xF0000000;
			if (prog->alive_flag == TRUE
				&& (getcolor(&prog->render, x + i, y + j) & check))
				prog->alive_flag = FALSE;
			img_pixel_put(&prog->render, x + i, y + j, color);
		}
	}
}

double	intrpl(double num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (num - old_min)
		/ (old_max - old_min) + new_min);
}
