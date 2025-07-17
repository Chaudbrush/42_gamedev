/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:41:36 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:56 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

void	set_score(t_data *prog, int i)
{
	if (i % 10 == 0)
	{
		prog->score++;
		prog->score += 3 * counters()->move_counter;
		if (prog->score > prog->best_score)
			prog->best_score = prog->score;
	}
}

void	put_score_to_img(t_data *prog)
{
	prog->scr_ofst = 0;
	ft_printnbr(prog, prog->score, 0, 10);
	put_img(&prog->render, &prog->text[1], prog->scr_ofst, 0);
	prog->scr_ofst = 8;
	put_img(&prog->render, &prog->text[0], prog->scr_ofst, 45);
	prog->scr_ofst += 48;
	ft_printnbr(prog, prog->best_score, 45, 0);
}

void	digit_to_screen(t_data *prog, unsigned long num, int y, int flag)
{
	if (num == 0)
		put_img(&prog->render, &prog->num[0 + flag], prog->scr_ofst, y);
	else if (num == 1)
		put_img(&prog->render, &prog->num[1 + flag], prog->scr_ofst, y);
	else if (num == 2)
		put_img(&prog->render, &prog->num[2 + flag], prog->scr_ofst, y);
	else if (num == 3)
		put_img(&prog->render, &prog->num[3 + flag], prog->scr_ofst, y);
	else if (num == 4)
		put_img(&prog->render, &prog->num[4 + flag], prog->scr_ofst, y);
	else if (num == 5)
		put_img(&prog->render, &prog->num[5 + flag], prog->scr_ofst, y);
	else if (num == 6)
		put_img(&prog->render, &prog->num[6 + flag], prog->scr_ofst, y);
	else if (num == 7)
		put_img(&prog->render, &prog->num[7 + flag], prog->scr_ofst, y);
	else if (num == 8)
		put_img(&prog->render, &prog->num[8 + flag], prog->scr_ofst, y);
	else if (num == 9)
		put_img(&prog->render, &prog->num[9 + flag], prog->scr_ofst, y);
	if (flag)
		prog->scr_ofst += 35;
	else
		prog->scr_ofst += 18;
}

void	ft_printnbr(t_data *prog, unsigned long num, int y, int flag)
{
	char	digit;

	if (num > 9)
		ft_printnbr(prog, num / 10, y, flag);
	digit = num % 10;
	digit_to_screen(prog, digit, y, flag);
}
