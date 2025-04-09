/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/09 22:26:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_window *game)
{
	int x;
  int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			char tile = game->map[y][x];

			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE, y * TILE);
			else if (tile == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE, y * TILE);
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE, y * TILE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collect, x * TILE, y * TILE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}