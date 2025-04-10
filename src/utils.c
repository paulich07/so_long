/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 03:18:53 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_window *win)
{
	int x;
  int y;


	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			char tile = win->map[y][x];

			if (tile == '1')
				mlx_put_image_to_window(win->mlx, win->win, win->img_wall, x * TILE, y * TILE);
			else if (tile == '0')
				mlx_put_image_to_window(win->mlx, win->win, win->img_floor, x * TILE, y * TILE);
			else if (tile == 'P')
				mlx_put_image_to_window(win->mlx, win->win, win->img_player, x * TILE, y * TILE);
			else if (tile == 'C')
				mlx_put_image_to_window(win->mlx, win->win, win->img_collect, x * TILE, y * TILE);
			else if (tile == 'E')
				mlx_put_image_to_window(win->mlx, win->win, win->img_exit, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

int  close_window(t_window *win)
{
  (void) win;
	write(1, "Exit\n", 5);
	exit(0);
  return (0);
}

int	is_walkable(t_window *win, int x, int y)
{
	if (y < 0 || x < 0 || y >= win->map_height || x >= win->map_width)
		return (0);

	if (win->map[y][x] != '1')
		return (1);

	return (0);
}

// alloco prima y altezza (numero di righe)
// poi x (lunghezza)
void	initialize_player_position(t_window *win)
{
	int x;
	int y;

	y = 0;
	while (y < win->map_height)
	{
			x = 0;
			while (x < win->map_width)
			{
					if (win->map[y][x] == 'P')
					{
							win->pos_x = x;
							win->pos_y = y;
							return ;
					}
					x++;
			}
			y++;
    }
		printf("pos y %d\n", win->pos_y);
		printf("pos x %d\n", win->pos_x);
}

void	move_player(t_window *win, int move_x, int move_y)
{
    if (is_walkable(win, win->pos_x + move_x, win->pos_y + move_y))
    {
				printf("is walkable\n");
        win->map[win->pos_y][win->pos_x] = '0';
				win->pos_x += move_x;
				win->pos_y += move_y;
        win->map[win->pos_y][win->pos_x] = 'P';
        render_map(win);
    }
		else
			printf("not walkable\n");
}
