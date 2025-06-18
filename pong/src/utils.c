/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:00:16 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:37 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

double	min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	interpolation(double num, double new_min, \
	double new_max, double old_max)
{
	double	old_min;

	old_min = 0;
	return ((new_max - new_min) * (num - old_min) / (old_max - old_min) \
			+ new_min);
}

int	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
	return (0);
}
