/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:48:20 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 19:19:55 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	ft_render(t_data *prog)
{
	set_vars(prog);
	put_img(&prog->render, &prog->bg,
		(unsigned int)counters()->bg % 1920, 0);
	render_enemies(prog, counters()->i / 10);
	render_mario(prog, counters()->i);
	if (prog->alive_flag == FALSE && prog->y_pos == MIN_POS)
		put_img(&prog->render, &prog->game_over, 0, 0);
	put_score_to_img(prog);
	mlx_put_image_to_window(prog->mlx, prog->win, prog->render.img, 0, 0);
	if (prog->alive_flag == FALSE)
		mario_img_to_img(prog, &prog->death, X_POS, prog->y_pos);
	return (0);
}

void	render_mario(t_data *prog, int i)
{
	i = i / 10;
	if (prog->alive_flag == TRUE)
	{
		if (prog->y_pos >= MAX_POS && prog->y_pos != MIN_POS)
		{
			if (prog->mov_flag == TRUE)
				mario_img_to_img(prog, &prog->fly[i % 4], X_POS, prog->y_pos);
			else
				mario_img_to_img(prog, &prog->fall, X_POS, prog->y_pos);
		}
		else if (prog->y_pos == MIN_POS)
			mario_img_to_img(prog, &prog->walk[i % 4], X_POS, prog->y_pos);
	}
}

void	mario_movement(t_data *prog)
{
	if (prog->old_acel != prog->acel_flag)
		prog->acel = 0;
	prog->acel += 0.5;
	if (prog->mov_flag == TRUE)
	{
		if (prog->y_pos > MAX_POS + 1)
			prog->y_pos -= prog->acel;
	}
	else if (prog->y_pos < MIN_POS)
		prog->y_pos += prog->acel;
	if (prog->y_pos > MIN_POS)
		prog->y_pos = MIN_POS;
	if (prog->y_pos < MAX_POS)
		prog->y_pos = MAX_POS;
	prog->old_acel = prog->acel_flag;
}

void	render_enemies(t_data *prog, int i)
{
	int			index;

	index = (i % 4) / 2;
	spawn_goomba(prog, index);
	spawn_plant(prog, index);
	spawn_turtle(prog, index, i);
	spawn_bomb(prog, index);
	spawn_bullet(prog, index);
}
