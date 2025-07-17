/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:16:46 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:30 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	ft_close(t_data *prog)
{
	save_score(prog);
	destroy_single_img(prog);
	destroy_multiple_img(prog);
	if (prog->win)
		mlx_destroy_window(prog->mlx, prog->win);
	if (prog->mlx)
		mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	free(prog);
	exit (0);
}

void	destroy_single_img(t_data *prog)
{
	if (prog->render.img)
		mlx_destroy_image(prog->mlx, prog->render.img);
	if (prog->bg.img)
		mlx_destroy_image(prog->mlx, prog->bg.img);
	if (prog->fall.img)
		mlx_destroy_image(prog->mlx, prog->fall.img);
	if (prog->death.img)
		mlx_destroy_image(prog->mlx, prog->death.img);
	if (prog->game_over.img)
		mlx_destroy_image(prog->mlx, prog->game_over.img);
	if (prog->bullet.img)
		mlx_destroy_image(prog->mlx, prog->bullet.img);
}

void	destroy_multiple_img(t_data *prog)
{
	free_images(prog, prog->gomba, 2);
	free_images(prog, prog->plnt, 2);
	free_images(prog, prog->turtle, 2);
	free_images(prog, prog->bomb, 2);
	free_images(prog, prog->text, 2);
	free_images(prog, prog->walk, 4);
	free_images(prog, prog->fly, 4);
	free_images(prog, prog->num, 20);
}

void	free_images(t_data *prog, t_img *img, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (img[i].img)
			mlx_destroy_image(prog->mlx, img[i].img);
		i++;
	}
}
