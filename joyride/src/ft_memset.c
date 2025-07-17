/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:45:33 by vloureir          #+#    #+#             */
/*   Updated: 2025/07/13 18:18:33 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/joyride.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;

	i = -1;
	new = (unsigned char *)s;
	while (++i < n)
		new[i] = c;
	return (s);
}
