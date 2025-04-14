/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 16:42:06 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	is_walkable(t_window *win, int x, int y)
{
	if (y < 0 || x < 0 || y >= win->map_height || x >= win->map_width)
		return (0);

	if (win->map[y][x] != '1')
		return (1);

	return (0);
}

void	count_coins(t_window *win)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'C')
				win->n_coins++;
			x++;
		}
		y++;
	}
	printf("coins %d\n", win->n_coins);
}