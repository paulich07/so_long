/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:00:26 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 16:11:18 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief check if string contains only allowed chars
/// @param s string to check
/// @param allowed string of allowed chars
/// @return 1 if string contains only allowed chars or 0 otherwise or if arguments are not valid 
int	contains_only(char *s, char *allowed)
{
	int	i;

	i = 0;
	if (!s || !allowed)
		return (0);
	while (s[i] != '\0')
	{
		// ft_printf("check if %c is different from %s\n", s[i], allowed);
		if (ft_strchr(allowed, s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
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

