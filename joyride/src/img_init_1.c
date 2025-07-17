/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 07:36:50 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/17 17:23:44 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

int	ft_init_images(t_data *prog)
{
	if (mario_imgs(prog) == -1 || enemy_imgs(prog) == -1
		|| num_imgs(prog) == -1
		|| load_bg(prog, &prog->bg, "./assets/bg.xpm") == -1
		|| load_bg(prog, &prog->game_over, "./assets/game_over.xpm") == -1)
		return (-1);
	return (0);
}

int	num_imgs(t_data *prog)
{
	if (load_nums(prog, &prog->num[0], "./assets/n/0_2.xpm") == -1
		|| load_nums(prog, &prog->num[1], "./assets/n/1_2.xpm") == -1
		|| load_nums(prog, &prog->num[2], "./assets/n/2_2.xpm") == -1
		|| load_nums(prog, &prog->num[3], "./assets/n/3_2.xpm") == -1
		|| load_nums(prog, &prog->num[4], "./assets/n/4_2.xpm") == -1
		|| load_nums(prog, &prog->num[5], "./assets/n/5_2.xpm") == -1
		|| load_nums(prog, &prog->num[6], "./assets/n/6_2.xpm") == -1
		|| load_nums(prog, &prog->num[7], "./assets/n/7_2.xpm") == -1
		|| load_nums(prog, &prog->num[8], "./assets/n/8_2.xpm") == -1
		|| load_nums(prog, &prog->num[9], "./assets/n/9_2.xpm") == -1
		|| load_nums(prog, &prog->num[10], "./assets/n/0_4.xpm") == -1
		|| load_nums(prog, &prog->num[11], "./assets/n/1_4.xpm") == -1
		|| load_nums(prog, &prog->num[12], "./assets/n/2_4.xpm") == -1
		|| load_nums(prog, &prog->num[13], "./assets/n/3_4.xpm") == -1
		|| load_nums(prog, &prog->num[14], "./assets/n/4_4.xpm") == -1
		|| load_nums(prog, &prog->num[15], "./assets/n/5_4.xpm") == -1
		|| load_nums(prog, &prog->num[16], "./assets/n/6_4.xpm") == -1
		|| load_nums(prog, &prog->num[17], "./assets/n/7_4.xpm") == -1
		|| load_nums(prog, &prog->num[18], "./assets/n/8_4.xpm") == -1
		|| load_nums(prog, &prog->num[19], "./assets/n/9_4.xpm") == -1
		|| load_nums(prog, &prog->text[0], "./assets/n/best.xpm") == -1
		|| load_nums(prog, &prog->text[1], "./assets/n/m.xpm") == -1)
		return (-1);
	return (0);
}

int	mario_imgs(t_data *prog)
{
	if (load_sprites(prog, &prog->walk[0], "./assets/walk0.xpm") == -1
		|| load_sprites(prog, &prog->walk[1], "./assets/walk1.xpm") == -1
		|| load_sprites(prog, &prog->walk[2], "./assets/walk2.xpm") == -1
		|| load_sprites(prog, &prog->walk[3], "./assets/walk1.xpm") == -1
		|| load_sprites(prog, &prog->fly[0], "./assets/fly0.xpm") == -1
		|| load_sprites(prog, &prog->fly[1], "./assets/fly1.xpm") == -1
		|| load_sprites(prog, &prog->fly[2], "./assets/fly2.xpm") == -1
		|| load_sprites(prog, &prog->fly[3], "./assets/fly3.xpm") == -1
		|| load_sprites(prog, &prog->fall, "./assets/fall.xpm") == -1
		|| load_sprites(prog, &prog->death, "./assets/death.xpm") == -1)
		return (-1);
	return (0);
}

int	enemy_imgs(t_data *prog)
{
	if (load_sprites(prog, &prog->gomba[0], "./assets/goomba0.xpm") == -1
		|| load_sprites(prog, &prog->gomba[1], "./assets/goomba1.xpm") == -1
		|| load_sprites(prog, &prog->plnt[0], "./assets/plant0.xpm") == -1
		|| load_sprites(prog, &prog->plnt[1], "./assets/plant1.xpm") == -1
		|| load_sprites(prog, &prog->bomb[0], "./assets/bomb0.xpm") == -1
		|| load_sprites(prog, &prog->bomb[1], "./assets/bomb1.xpm") == -1
		|| load_sprites(prog, &prog->turtle[0], "./assets/turtle0.xpm") == -1
		|| load_sprites(prog, &prog->turtle[1], "./assets/turtle1.xpm") == -1
		|| load_sprites(prog, &prog->bullet, "./assets/bullet0.xpm") == -1)
		return (-1);
	return (0);
}
