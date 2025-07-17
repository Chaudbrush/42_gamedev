/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:14:48 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 16:12:11 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	ft_mlx_init(t_data *prog)
{
	prog->mlx = mlx_init();
	if (prog->mlx == NULL)
		return (-1);
	prog->win = mlx_new_window(prog->mlx, WIDTH, HEIGHT, "Joyride");
	if (prog->win == NULL)
		return (-1);
	prog->render.img = mlx_new_image(prog->mlx, WIDTH + (WIDTH / 2), HEIGHT);
	if (prog->render.img == NULL)
		return (-1);
	prog->render.addr = mlx_get_data_addr(prog->render.img, &prog->render.bpp,
			&prog->render.line_len, &prog->render.endian);
	if (ft_init_images(prog) == -1)
		return (-1);
	ft_init_pos();
	ft_init_vars(prog);
	srand(time(NULL));
	return (0);
}

void	ft_init_vars(t_data *prog)
{
	prog->y_pos = MIN_POS;
	prog->mov_flag = FALSE;
	prog->acel = 0;
	prog->coins = 0;
	prog->acel_flag = FALSE;
	prog->old_acel = FALSE;
	prog->alive_flag = TRUE;
	prog->level = 0;
	prog->score = 0;
	prog->sign[0] = 1;
	prog->sign[1] = -1;
}

void	ft_init_pos(void)
{
	const int		y[6] = {MAX_POS, MAX_POS, 150, 250, 350, 350};

	pos()->gb_x[0] = 1500;
	pos()->gb_x[1] = 1500;
	pos()->gb_bool[0] = FALSE;
	pos()->gb_bool[1] = FALSE;
	pos()->bb_x = 1100;
	pos()->bb_bool = FALSE;
	pos()->pt_x[0] = 1600;
	pos()->pt_x[1] = 1500;
	pos()->pt_y[0] = y[rand() % 6];
	pos()->pt_y[1] = y[rand() % 6];
	pos()->pt_bool[0] = FALSE;
	pos()->pt_bool[1] = FALSE;
	pos()->bt_x[0] = 1300;
	pos()->bt_x[1] = 1650;
	pos()->bt_bool[0] = FALSE;
	pos()->bt_bool[1] = FALSE;
	pos()->tt_x = 1500;
	pos()->tt_y = y[(rand() % 4) + 2];
	pos()->tt_bool = FALSE;
}

t_vars	*counters(void)
{
	static t_vars	var;

	return (&var);
}

t_pos	*pos(void)
{
	static t_pos	pos;

	return (&pos);
}
