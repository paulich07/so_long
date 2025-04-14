/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 23:11:55 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void deallocate_map(char **map, int height)
{
	int i;

	i = 0;
	if (!map || !*map)
		return;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/// @brief create a dynamically allocated copy of the map 
/// @param win general structure containing pointers to both the original map and the copy 
void	copy_map(t_window *win)
{
	int	i;

	if (!win->map)
		exit_program(win, "Map not saved properly: impossible to copy", 1);
	if (win->map_height < 1)
		exit_program(win, "Map height not appropriate", 1);
	if (win->map_width < 1)
		exit_program(win, "Map width not appropriate", 1);		
	win->map_copy = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!win->map_copy)
		exit_program(win, "Map not allocated properly", 1);
	i = 0;
	while(i < win->map_height)
	{
		win->map_copy[i] = ft_strdup(win->map[i]);
		if (!win->map_copy[i])
		{
			deallocate_map(win->map_copy, i);
			exit_program(win, "Map line not allocated properly", 1);		
		}
		i++;
	}
	win->map_copy[i] = NULL;
}

void	put_images(t_window *win)
{
	int img_width;
	int img_height;
	
	img_width = TILE;
	img_height = TILE;

	win->img_floor = mlx_xpm_file_to_image(win->mlx, "textures/floor.xpm", &img_width, &img_height);
	win->img_wall = mlx_xpm_file_to_image(win->mlx, "textures/wall.xpm", &img_width, &img_height);
	win->img_player = mlx_xpm_file_to_image(win->mlx, "textures/player.xpm", &img_width, &img_height);
	win->img_collect = mlx_xpm_file_to_image(win->mlx, "textures/collect.xpm", &img_width, &img_height);
	win->img_exit = mlx_xpm_file_to_image(win->mlx, "textures/exit.xpm", &img_width, &img_height);

	if (!win->img_floor || !win->img_wall || !win->img_player || !win->img_collect || !win->img_exit)
		exit_program(win, "Image missing or not loaded properly", 1);
}

void	render_map(t_window *win)
{
	char	tile;
	int	x;
	int	y;

	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			tile = win->map[y][x];
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
