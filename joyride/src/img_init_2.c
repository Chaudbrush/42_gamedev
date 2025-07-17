/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 07:36:50 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 16:10:35 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	load_sprites(t_data *prog, t_img *img, char *str)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(prog->mlx, str, &width, &height);
	if (img->img == NULL)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	img->w = SPRITE;
	img->h = SPRITE;
	return (0);
}

int	load_bg(t_data *prog, t_img *img, char *str)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(prog->mlx, str, &width, &height);
	if (img->img == NULL)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	img->w = WIDTH + (WIDTH / 2);
	img->h = HEIGHT;
	return (0);
}

int	load_nums(t_data *prog, t_img *img, char *str)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(prog->mlx, str, &width, &height);
	if (img->img == NULL)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	img->w = NUM_SPRITE;
	img->h = NUM_SPRITE;
	return (0);
}
