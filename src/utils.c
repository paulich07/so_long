/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 17:24:11 by plichota         ###   ########.fr       */
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
