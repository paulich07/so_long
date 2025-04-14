/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 19:48:22 by plichota         ###   ########.fr       */
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

/// @brief check if string contains only allowed chars
/// @param s string to check
/// @param allowed string of allowed chars
/// @return 1 if a valid string contains only allowed chars 0 otherwise
int	contains_only(char *s, char *allowed)
{
	int	i;

	i = 0;
	if (!s || !allowed)
		return (0);
	while (s[i] != '\0')
	{
		if (ft_strchr(allowed, s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(t_window *win, t_elements *elem, int curr_y, int curr_x)
{
	if (curr_y < 0 || curr_y > win->map_height
		|| curr_x < 0 || curr_x > win->map_width
		|| win->map_copy[curr_y][curr_x] == '1'
		|| win->map_copy[curr_y][curr_x] == 'R')
		return ;
	if (win->map_copy[curr_y][curr_x] == 'C')
		elem->n_coins++;
	if (win->map_copy[curr_y][curr_x] == 'P')
		elem->n_players++;
	if (win->map_copy[curr_y][curr_x] == 'E')
		elem->n_exit++;
	win->map_copy[curr_y][curr_x] = 'R';
	flood_fill(win, elem, curr_y + 1, curr_x);
	flood_fill(win, elem, curr_y - 1, curr_x);
	flood_fill(win, elem, curr_y, curr_x + 1);
	flood_fill(win, elem, curr_y, curr_x - 1);
}
