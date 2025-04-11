/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/12 00:44:45 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_map(char *filename, t_window *win)
{
	int	n_lines;
	char	**map;
	char  *line;
	int fd;
	int	i;

	if (!filename)
		exit_program(win, "Filename not specified");
	n_lines = count_lines(filename);
	printf("n lines: %d\n", n_lines);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
		exit_program(win, "Map not allocated properly");
	i = 0;
	if (!filename)
		exit_program(win, "File is not valid");
	if (!is_valid_filename(filename))
		exit_program(win, "File not provided");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening");
	line = get_next_line(fd);
	while(line != NULL)
	{
		// printf("alloco %s di lunghezza %ld\n", line, ft_strlen(line));
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void deallocate_map(char **map)
{
	int i;

	i = 0;
	ft_printf("deallocate map\n");
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
