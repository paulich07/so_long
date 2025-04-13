/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/13 10:36:45 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_map(t_window *win, char *filename)
{
	int	n_lines;
	char	**map;
	char  *line;
	int fd;
	int	i;

	if (!filename)
		exit_program(win, "Filename not specified");
	n_lines = count_lines(win, filename);	
	if (n_lines < 1)
		exit_program(win, "No lines to read");		
	ft_printf("n lines: %d\n", n_lines);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
		exit_program(win, "Map not allocated properly");
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening");
	line = get_next_line(fd);
	while(line != NULL)
	{
		ft_printf("alloco [%d] %s di lunghezza %ld\n", i, line, ft_strlen(line));
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char **copy_map(t_window *win)
{
	char	**map;
	int	i;

	if (!win->map)
		exit_program(win, "Map not saved properly: impossible to copy");
	if (win->map_height < 1)
		exit_program(win, "Map height not appropriate");
	if (win->map_width < 1)
		exit_program(win, "Map width not appropriate");		
	ft_printf("n lines: %d\n", win->map_height);
	map = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!map)
		exit_program(win, "Map not allocated properly");
	
	i = 0;
	while(line != NULL)
	{
		ft_printf("alloco [%d] %s di lunghezza %ld\n", i, line, ft_strlen(line));
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