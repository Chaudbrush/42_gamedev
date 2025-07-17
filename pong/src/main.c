/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:02:26 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/19 21:54:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

int	main(void)
{
	t_data	prog;

	srand(time(NULL));
	ft_mlx_init(&prog);
	mlx_loop_hook(prog.mlx, render_img, &prog);
	mlx_hook(prog.win, KeyPress, KeyPressMask, handle_keypress, &prog);
	mlx_hook(prog.win, KeyRelease, KeyReleaseMask, handle_keyrelease, &prog);
	mlx_hook(prog.win, DestroyNotify, NoEventMask, close_all, &prog);
	mlx_loop(prog.mlx);
}

int	ft_mlx_init(t_data *prog)
{
	prog->mlx = mlx_init();
	if (prog->mlx == NULL)
		exit (MLX_ERROR);
	prog->win = mlx_new_window(prog->mlx, WIDTH, HEIGHT, "Pong");
	if (prog->win == NULL)
		ft_close_min(prog);
	prog->img.img = mlx_new_image(prog->mlx, WIDTH, HEIGHT);
	if (prog->img.img == NULL)
		ft_close_half(prog);
	prog->img.addr = mlx_get_data_addr(prog->img.img, &prog->img.bpp, \
						&prog->img.line_len, &prog->img.endian);
	ft_init_data(prog);
	return (0);
}

int	handle_keypress(int keysym, t_data *prog)
{
	if (keysym == XK_Escape)
		close_all(prog);
	if (keysym == XK_w)
		prog->utils.p1_w = TRUE;
	if (keysym == XK_s)
		prog->utils.p1_s = TRUE;
	if (keysym == XK_Up)
		prog->utils.p2_up = TRUE;
	if (keysym == XK_Down)
		prog->utils.p2_down = TRUE;
	if (keysym == XK_space && prog->utils.start == FALSE)
	{
		prog->utils.y_speed = interpolation(rand() % 31, 1.2, 1.8, 30);
		prog->utils.x_speed = 2.1;
		prog->utils.start = TRUE;
	}
	if (keysym == XK_Tab)
	{
		if (prog->utils.start == TRUE)
			prog->utils.start = FALSE;
		else
			prog->utils.start = TRUE;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *prog)
{
	if (keysym == XK_w)
		prog->utils.p1_w = FALSE;
	if (keysym == XK_s)
		prog->utils.p1_s = FALSE;
	if (keysym == XK_Up)
		prog->utils.p2_up = FALSE;
	if (keysym == XK_Down)
		prog->utils.p2_down = FALSE;
	return (0);
}

void	ft_init_data(t_data *prog)
{
	prog->utils.offset_p1 = 0;
	prog->utils.offset_p2 = 0;
	prog->utils.offset_bar = WIDTH / 10;
	prog->utils.ball_x = 0;
	prog->utils.ball_y = 0;
	prog->utils.score_p1 = 0;
	prog->utils.score_p2 = 0;
	prog->utils.p1_w = FALSE;
	prog->utils.start = FALSE;
	prog->utils.p1_s = FALSE;
	prog->utils.p2_up = FALSE;
	prog->utils.p2_down = FALSE;
	prog->utils.sign[0] = 1;
	prog->utils.sign[1] = -1;
	prog->utils.y_speed = 0;
	prog->utils.x_speed = 0;
	prog->utils.ball_x_sign = prog->utils.sign[(rand() % 2)];
	prog->utils.ball_y_sign = prog->utils.sign[(rand() % 2)];
	prog->utils.collision = TRUE;
}
