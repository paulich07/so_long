/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/13 09:53:46 by plichota         ###   ########.fr       */
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
	printf("n lines: %d\n", n_lines);
	
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
		// SE GET NEXT LINE FALLISCE???!1
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void deallocate_map(char **map, int height)
{
	int i;

	i = 0;
	ft_printf("deallocate map\n");
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
