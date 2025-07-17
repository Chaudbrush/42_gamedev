/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:25:51 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 17:22:09 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

void	spawn_plant(t_data *prog, int i)
{
	const int		y[6] = {MAX_POS, MAX_POS, 150, 250, 350, 350};

	if (prog->alive_flag == TRUE)
		pos()->pt_x[0] -= 1 + counters()->move_counter;
	if (pos()->pt_x[0] < -150)
	{
		pos()->pt_x[0] = 1500;
		pos()->pt_y[0] = y[rand() % 6];
	}
	if ((int)prog->score % 38 == 34 && (pos()->pt_x[1] + 250 < pos()->pt_x[0]
			|| pos()->pt_x[1] - 250 > pos()->pt_x[0]))
		pos()->pt_bool[1] = TRUE;
	put_img(&prog->render, &prog->plnt[i], pos()->pt_x[0], pos()->pt_y[0]);
	if (pos()->pt_bool[1] == TRUE)
	{
		if (prog->alive_flag == TRUE)
			pos()->pt_x[1] -= 1 + counters()->move_counter;
		put_img(&prog->render, &prog->plnt[i], pos()->pt_x[1], pos()->pt_y[1]);
		if (pos()->pt_x[1] < -150)
		{
			pos()->pt_x[1] = 1700;
			pos()->pt_y[1] = y[rand() % 6];
			pos()->pt_bool[1] = FALSE;
		}
	}
}

void	spawn_bullet(t_data *prog, int i)
{
	(void)i;
	if (((int)prog->score % 86 == 63 || (int)prog->score % 68 == 32)
		&& pos()->bt_bool[0] == FALSE)
	{
		pos()->bt_y[0] = prog->y_pos;
		pos()->bt_bool[0] = TRUE;
	}
	if (pos()->bt_bool[0] == TRUE)
	{
		if (rand() % 10 == 4 && pos()->bt_bool[1] == FALSE
			&& pos()->bt_x[0] > 1300)
		{
			pos()->bt_y[1] = prog->y_pos + (20 * prog->sign[rand() % 2]);
			pos()->bt_bool[1] = TRUE;
		}
		if (prog->alive_flag == TRUE)
			pos()->bt_x[0] -= 3.8 + counters()->move_counter;
		pos()->bt_x[1] = pos()->bt_x[0] + 100;
		put_img(&prog->render, &prog->bullet, pos()->bt_x[0], pos()->bt_y[0]);
		if (pos()->bt_bool[1] == TRUE)
			put_img(&prog->render, &prog->bullet, pos()->bt_x[1],
				pos()->bt_y[1]);
		if (pos()->bt_x[0] < -250)
			mini_reset_bullet();
	}
}

void	spawn_turtle(t_data *prog, int i, int old_i)
{
	const int	y[5] = {70, 120, 170, 220, 270};
	int			trtl_pos;

	if (((int)prog->score % 62 == 26 || (int)prog->score % 96 == 48)
		&& counters()->move_counter > 2.1)
		pos()->tt_bool = TRUE;
	if (pos()->tt_bool == TRUE)
	{
		if (prog->alive_flag == TRUE)
			pos()->tt_x -= 1 + counters()->move_counter;
		trtl_pos = intrpl(cos(old_i % 20), pos()->tt_y, pos()->tt_y + 80, 1);
		put_img(&prog->render, &prog->turtle[i],
			pos()->tt_x * 1.2, trtl_pos);
		if (pos()->tt_x < -250)
		{
			pos()->tt_x = 1500;
			pos()->tt_y = y[rand() % 5];
			pos()->tt_bool = FALSE;
		}
	}
}

void	spawn_bomb(t_data *prog, int i)
{
	if ((int)prog->score % 42 == 17 || (int)prog->score % 71 == 29)
		pos()->bb_bool = TRUE;
	if (pos()->bb_bool == TRUE)
	{
		if (prog->alive_flag == TRUE)
			pos()->bb_x -= 1 + counters()->move_counter;
		put_img(&prog->render, &prog->bomb[i], pos()->bb_x * 1.4, MIN_POS);
		if (pos()->bb_x < -250)
		{
			pos()->bb_x = 1100;
			pos()->bb_bool = FALSE;
		}
	}
}

void	spawn_goomba(t_data *prog, int i)
{
	if (prog->alive_flag == TRUE)
		pos()->gb_x[0] -= 1 + counters()->move_counter;
	if (pos()->gb_x[0] < -150)
		pos()->gb_x[0] = 1500;
	if ((int)prog->score % 26 == 12 && (pos()->gb_x[1] + 250 < pos()->gb_x[0]
			|| pos()->gb_x[1] - 250 > pos()->gb_x[0]))
		pos()->gb_bool[1] = TRUE;
	put_img(&prog->render, &prog->gomba[i], pos()->gb_x[0] * 1.2, MIN_POS);
	if (pos()->gb_bool[1] == TRUE)
	{
		if (prog->alive_flag == TRUE)
			pos()->gb_x[1] -= 1 + counters()->move_counter;
		put_img(&prog->render, &prog->gomba[i], pos()->gb_x[1] * 1.2, MIN_POS);
		if (pos()->gb_x[1] < -150)
		{
			pos()->gb_x[1] = 1500;
			pos()->gb_bool[1] = FALSE;
		}
	}
}
