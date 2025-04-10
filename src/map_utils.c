/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 15:42:14 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_map(char *filename)
{
	int	n_lines;
	char	**map;
	char  *line;
	int fd;
	int	i;

	if (!filename)
		return (ft_printf("Filename not specified\n"), NULL);
	// ALLOCAZIONE COLONNE!!!--------------------------------
	n_lines = count_lines(filename);
	printf("n lines: %d\n", n_lines);
	map = ft_calloc(n_lines + 1, sizeof(char *));
	if (!map)
		return (ft_printf("Map not allocated properly\n"), NULL);

	// ALLOCAZIONE RIGHE!!!-----------------------------------
	i = 0;
	if (!filename)
		return (ft_printf("File not provided\n"), NULL);
	if (!is_valid_filename(filename))
		return (ft_printf("File is not valid\n"), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error in file opening\n"), NULL);
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
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
