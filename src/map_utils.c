/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 17:02:01 by plichota         ###   ########.fr       */
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
	{
		ft_printf("Filename not specified\n");
		exit_program(win);
	}
	// ALLOCAZIONE COLONNE!!!--------------------------------
	n_lines = count_lines(filename);
	printf("n lines: %d\n", n_lines);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
	{
		ft_printf("Map not allocated properly\n");
		exit_program(win);
	}

	// ALLOCAZIONE RIGHE!!!-----------------------------------
	i = 0;
	if (!filename)
	{
		ft_printf("File is not valid\n");
		exit_program(win);
	}
	if (!is_valid_filename(filename))
	{
		ft_printf("File not provided\n");
		exit_program(win);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error in file opening\n");
		exit_program(win);
	}
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("alloco %s di lunghezza %ld\n", line, ft_strlen(line));
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
	printf("deallocate map\n");
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
