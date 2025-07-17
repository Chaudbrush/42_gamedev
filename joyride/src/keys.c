/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:14:48 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:49 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	handle_keypress(int keysym, t_data *prog)
{
	if (keysym == XK_Escape)
		ft_close(prog);
	if (keysym == XK_space && prog->alive_flag)
	{
		prog->mov_flag = TRUE;
		prog->acel_flag = TRUE;
	}
	if (keysym == XK_Tab && prog->alive_flag == FALSE)
	{
		reset_state(prog);
		prog->alive_flag = TRUE;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *prog)
{
	if (keysym == XK_Escape)
		ft_close(prog);
	if (keysym == XK_space)
	{
		prog->mov_flag = FALSE;
		prog->acel_flag = FALSE;
	}
	return (0);
}
