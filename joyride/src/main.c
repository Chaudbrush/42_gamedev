/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:53:18 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:50 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	main(void)
{
	t_data	*prog;

	prog = malloc(sizeof(t_data));
	if (prog == NULL)
		return (EXIT_FAILURE);
	prog = ft_memset(prog, 0, sizeof(t_data));
	if (ft_mlx_init(prog) == -1)
		ft_close(prog);
	init_score(prog);
	mlx_loop_hook(prog->mlx, ft_render, prog);
	mlx_hook(prog->win, KeyPress, KeyPressMask, handle_keypress, prog);
	mlx_hook(prog->win, KeyRelease, KeyReleaseMask, handle_keyrelease, prog);
	mlx_hook(prog->win, DestroyNotify, NoEventMask, ft_close, prog);
	mlx_loop(prog->mlx);
}
