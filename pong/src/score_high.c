/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_high.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:39:37 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:34 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

void	print_five(t_img *img, int offset_x, int offset_y)
{
	int	a;
	int	b;

	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if (a < 5 || b < 5 || a > 14 || b > 34 || (b > 14 && b < 20))
				img_pixel_put(img, a + offset_x, b + offset_y, 0xFFFFFF);
			else
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if ((a < 5 && b > 19 && b < 35) || (a > 14 && b > 4 && b < 15))
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
}

void	print_six(t_img *img, int offset_x, int offset_y)
{
	int	a;
	int	b;

	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if (a < 5 || b < 5 || a > 14 || b > 34 || (b > 14 && b < 20))
				img_pixel_put(img, a + offset_x, b + offset_y, 0xFFFFFF);
			else
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if ((a > 4 && b < 5) || (a > 14 && b > 4 && b < 15))
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
}

void	print_seven(t_img *img, int offset_x, int offset_y)
{
	int	a;
	int	b;

	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if (a < 15 && b > 5)
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
			else
				img_pixel_put(img, a + offset_x, b + offset_y, 0xFFFFFF);
		}
	}
}

void	print_eight(t_img *img, int offset_x, int offset_y)
{
	int	a;
	int	b;

	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if (a < 5 || b < 5 || a > 14 || b > 34 || (b > 14 && b < 20))
				img_pixel_put(img, a + offset_x, b + offset_y, 0xFFFFFF);
			else
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
}

void	print_nine(t_img *img, int offset_x, int offset_y)
{
	int	a;
	int	b;

	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if (a < 5 || b < 5 || a > 14 || b > 34 || (b > 14 && b < 20))
				img_pixel_put(img, a + offset_x, b + offset_y, 0xFFFFFF);
			else
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
	b = -1;
	while (++b < 40)
	{
		a = -1;
		while (++a < 20)
		{
			if ((a < 5 && b > 19) || (a < 15 && b > 34))
				img_pixel_put(img, a + offset_x, b + offset_y, 0x000000);
		}
	}
}
