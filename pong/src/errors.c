/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:59:59 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:24 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

int	close_all(t_data *prog)
{
	mlx_destroy_image(prog->mlx, prog->img.img);
	mlx_destroy_window(prog->mlx, prog->win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	write(1, "Thank you for playing!\n", 23);
	exit (EXIT_SUCCESS);
}

int	ft_close_half(t_data *prog)
{
	mlx_destroy_window(prog->mlx, prog->win);
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	exit (MLX_ERROR);
}

int	ft_close_min(t_data *prog)
{
	mlx_destroy_display(prog->mlx);
	free(prog->mlx);
	exit (MLX_ERROR);
}
