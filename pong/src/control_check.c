/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:41:16 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:18 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

int	check_movement(t_utils *utils)
{
	if (utils->p1_w == TRUE)
	{
		if (utils->offset_p1 > -300)
			utils->offset_p1 -= 5;
	}
	if (utils->p1_s == TRUE)
	{
		if (utils->offset_p1 < 300)
			utils->offset_p1 += 5;
	}
	if (utils->p2_up == TRUE)
	{
		if (utils->offset_p2 > -300)
			utils->offset_p2 -= 5;
	}
	if (utils->p2_down == TRUE)
	{
		if (utils->offset_p2 < 300)
			utils->offset_p2 += 5;
	}
	return (0);
}

void	check_colision(t_data *prog, t_utils *utils)
{
	double	contact_1;
	double	contact_2;

	contact_1 = utils->offset_p1 - utils->ball_y;
	contact_2 = utils->offset_p2 - utils->ball_y;
	if (utils->ball_y >= 332 - utils->y_speed)
		utils->ball_y_sign *= -1;
	else if (utils->ball_y <= -332 + utils->y_speed)
		utils->ball_y_sign *= -1;
	if (utils->ball_x > -506 && utils->ball_x < -471 && contact_1 <= 74 && \
		contact_1 >= -74 && utils->collision == TRUE)
		pivot_p1(utils);
	else if (utils->ball_x > 471 && utils->ball_x < 506 && contact_2 <= 74 && \
			contact_2 >= -74 && utils->collision == TRUE)
		pivot_p2(utils);
	if (utils->ball_x >= 610)
		reset_game(prog, utils, 1);
	if (utils->ball_x <= -610)
		reset_game(prog, utils, 2);
}

void	reset_game(t_data *prog, t_utils *utils, int x)
{
	if (x == 1)
		utils->score_p1++;
	if (x == 2)
		utils->score_p2++;
	if (utils->score_p1 == 30 || utils->score_p2 == 30)
		close_all(prog);
	utils->start = PAUSE;
	utils->collision = TRUE;
	utils->ball_x = 0;
	utils->ball_y = 0;
	utils->y_speed = interpolation(rand() % 31, 1.2, 1.8, 30);
	utils->x_speed = 2.1;
	utils->ball_x_sign = utils->sign[(rand() % 2)];
	utils->ball_y_sign = utils->sign[(rand() % 2)];
}

void	pivot_p1(t_utils *utils)
{
	if (utils->p1_w && utils->ball_y - utils->old_y > 0)
	{
		utils->x_speed = min(utils->x_speed * 1.05, 3.6);
		utils->y_speed = min(utils->y_speed + (utils->x_speed / 4.2), 9);
		utils->ball_y_sign *= -1;
	}
	else if (utils->p1_s && utils->ball_y - utils->old_y < 0)
	{
		utils->x_speed = min(utils->x_speed * 1.05, 3.6);
		utils->y_speed = min(utils->y_speed + (utils->x_speed / 4.2), 9);
		utils->ball_y_sign *= -1;
	}
	utils->ball_x_sign *= -1;
	utils->x_speed = min(utils->x_speed * 1.02, 3.6);
	utils->collision = FALSE;
}

void	pivot_p2(t_utils *utils)
{
	if (utils->p2_up && utils->ball_y - utils->old_y > 0)
	{
		utils->x_speed = min(utils->x_speed * 1.05, 3.6);
		utils->y_speed = min(utils->y_speed + (utils->x_speed / 4.2), 9);
		utils->ball_y_sign *= -1;
	}
	else if (utils->p2_down && utils->ball_y - utils->old_y < 0)
	{
		utils->x_speed = min(utils->x_speed * 1.05, 3.6);
		utils->y_speed = min(utils->y_speed + (utils->x_speed / 4.2), 9);
		utils->ball_y_sign *= -1;
	}
	utils->ball_x_sign *= -1;
	utils->x_speed = min(utils->x_speed * 1.02, 3.6);
	utils->collision = FALSE;
}
