/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:41:36 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:57 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

void	init_score(t_data *prog)
{
	int				fd;
	int				size;
	int				bytes_read;
	char			buffer[100];

	fd = open("score.txt", O_CREAT | O_RDONLY, 0644);
	if (fd < 0)
		return ;
	bytes_read = 1;
	size = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, 100);
		size += bytes_read;
	}
	close(fd);
	buffer[size] = '\0';
	prog->best_score = atoi(buffer);
}

void	save_score(t_data *prog)
{
	int	fd;

	fd = open("score.txt", O_TRUNC | O_WRONLY);
	if (fd < 0)
		return ;
	ft_putnbr_fd(prog->best_score, fd);
	close(fd);
}

void	ft_putnbr_fd(unsigned long num, int fd)
{
	char	digit;

	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	digit = (num % 10) + '0';
	write(fd, &digit, 1);
}
