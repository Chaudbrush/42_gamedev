/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:15:05 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

t_time	*time_vars(void)
{
	static t_time	var;

	return (&var);
}

static uint64_t	gettimeofday_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

static uint64_t	timestamp_in_ms(void)
{
	if (time_vars()->created_at == 0)
		time_vars()->created_at = gettimeofday_ms();
	return (gettimeofday_ms() - time_vars()->created_at);
}

int	update(void)
{
	const int	fps = 60;

	if (timestamp_in_ms() - time_vars()->updated_at < (uint64_t)(1000 / fps))
		return (0);
	time_vars()->updated_at = timestamp_in_ms();
	return (1);
}
