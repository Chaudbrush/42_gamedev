/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:54:09 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:59 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	ft_min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}

void	set_vars(t_data *prog)
{
	if (prog->alive_flag == TRUE)
	{
		if (update())
		{
			counters()->i++;
			set_score(prog, counters()->i);
			mario_movement(prog);
		}
		counters()->move_counter = fmin(4.5, (prog->score / 210.0));
		counters()->level++;
		counters()->move += 1 + counters()->move_counter;
		counters()->bg -= 1 + counters()->move_counter;
	}
	else if (prog->alive_flag == FALSE)
	{
		if (update())
			mario_movement(prog);
	}
	if (counters()->level == 0)
		prog->level++;
}
