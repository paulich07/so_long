/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:00:26 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 18:23:17 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(t_window *win)
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
			if (win->map[y][x] == 'P')
				win->n_players++;
			if (win->map[y][x] == 'E')
				win->n_exit++;
			x++;
		}
		y++;
	}
	// ft_printf("coins %d\n players %d\n exit %d\n", win->n_coins, win->n_players, win->n_exit);
}

void	check_walls(t_window *win, char **map)
{
	int	i;

	i = 1;
	// check first and last line
	if (!contains_only(map[0], "1") || !contains_only(map[win->map_height - 1], "1"))
		exit_program(win, "Invalid walls: map not closed properly");
	// check inner walls
	while (i < win->map_height - 1)
	{
		if (!contains_only(map[i], "01EPC"))
			exit_program(win, "Invalid character found in map");
		if (map[i][0] != '1' || map[i][win->map_width - 1] != '1')
			exit_program(win, "Invalid walls: map not closed properly");
		i++;
	}
}

void	check_counted_elements(t_window *win)
{
	if (win->n_exit != 1)
		exit_program(win, "Invalid number of Exit (E)");
	if (win->n_players != 1)
		exit_program(win, "Invalid number of Players (P)");
	if (win->n_coins < 1)
		exit_program(win, "Invalid number of Collectables (C)");
}


void	check_reachable(t_window *win)
{
	t_elements elem = {0};
	// check player position
	if (!win->pos_x || !win->pos_y)
		exit_program(win, "Invalid player position");
	flood_fill(win, &elem, win->pos_y, win->pos_x);
	// check if elements are equal
	ft_printf("players: %d, reached %d\n", win->n_players, elem.n_players);
	ft_printf("exit: %d, reached %d\n", win->n_exit, elem.n_exit);
	ft_printf("coins: %d, reached %d\n", win->n_coins, elem.n_coins);
	if (win->n_exit != elem.n_exit || win->n_players != elem.n_players
		|| win->n_coins != elem.n_coins)
		exit_program(win, "Invalid map: not all elements are reachable");		
}