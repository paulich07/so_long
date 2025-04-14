/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 16:13:24 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_map(t_window *win, char *filename)
{
	char	**map;
	char  *line;
	int fd;
	int	i;

	if (!filename)
		exit_program(win, "Filename not specified");
	win->map_height = count_lines(win, filename);
	if (win->map_height < 1)
		exit_program(win, "No lines to read");		
	map = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!map)
		exit_program(win, "Map not allocated properly");
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening");
	line = get_next_line(fd);
	if (!line)
		exit_program(win, "Error: first line of map empty");
	win->map_width = ft_strlen(line);
	if (line[win->map_width - 1] == '\n')
		line[win->map_width - 1] = '\0';
	win->map_width = ft_strlen(line);
	while(line != NULL)
	{
		if (line[(ft_strlen(line)) - 1] == '\n')
			line[(ft_strlen(line)) - 1] = '\0';
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void deallocate_map(char **map, int height)
{
	int i;

	i = 0;
	// ft_printf("deallocate map\n");
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
		exit_program(win, "Map not saved properly: impossible to copy");
	if (win->map_height < 1)
		exit_program(win, "Map height not appropriate");
	if (win->map_width < 1)
		exit_program(win, "Map width not appropriate");		
	win->map_copy = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!win->map_copy)
		exit_program(win, "Map not allocated properly");
	i = 0;
	while(i < win->map_height)
	{
		// ft_printf("alloco [%d] %s di lunghezza %d\n", i, win->map[i], win->map_width);
		win->map_copy[i] = ft_strdup(win->map[i]);
		if (!win->map_copy[i])
		{
			deallocate_map(win->map_copy, i);
			exit_program(win, "(Copy) Map line not allocated properly");		
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
		exit_program(win, "Image not loaded properly");
}