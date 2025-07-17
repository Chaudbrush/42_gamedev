/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:49:47 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:54 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

void	reset_state(t_data *prog)
{
	counters()->i = 0;
	counters()->move = 0;
	counters()->bg = 0;
	counters()->level = 0;
	prog->y_pos = MIN_POS;
	prog->mov_flag = FALSE;
	prog->acel = 0;
	prog->coins = 0;
	prog->acel_flag = FALSE;
	prog->old_acel = FALSE;
	prog->alive_flag = TRUE;
	prog->level = 0;
	prog->score = 0;
	ft_init_pos();
}

void	mini_reset_bullet(void)
{
	pos()->bt_x[0] = 1350;
	pos()->bt_bool[0] = FALSE;
	pos()->bt_bool[1] = FALSE;
}
