/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:22:13 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 22:44:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pong.h"

void	print_score(t_img *img, t_utils *utils)
{
	score_p1(img, utils->score_p1 / 10, 540, 60);
	score_p1(img, utils->score_p1 % 10, 580, 60);
	score_p2(img, utils->score_p2 / 10, 700, 60);
	score_p2(img, utils->score_p2 % 10, 740, 60);
}

int	score_p1(t_img *img, int digit, int x, int y)
{
	if (digit == 0)
		print_zero(img, x, y);
	if (digit == 1)
		print_one(img, x, y);
	if (digit == 2)
		print_two(img, x, y);
	if (digit == 3)
		print_three(img, x, y);
	if (digit == 4)
		print_four(img, x, y);
	if (digit == 5)
		print_five(img, x, y);
	if (digit == 6)
		print_six(img, x, y);
	if (digit == 7)
		print_seven(img, x, y);
	if (digit == 8)
		print_eight(img, x, y);
	if (digit == 9)
		print_nine(img, x, y);
	return (0);
}

int	score_p2(t_img *img, int digit, int x, int y)
{
	if (digit == 0)
		print_zero(img, x, y);
	if (digit == 1)
		print_one(img, x, y);
	if (digit == 2)
		print_two(img, x, y);
	if (digit == 3)
		print_three(img, x, y);
	if (digit == 4)
		print_four(img, x, y);
	if (digit == 5)
		print_five(img, x, y);
	if (digit == 6)
		print_six(img, x, y);
	if (digit == 7)
		print_seven(img, x, y);
	if (digit == 8)
		print_eight(img, x, y);
	if (digit == 9)
		print_nine(img, x, y);
	return (0);
}
