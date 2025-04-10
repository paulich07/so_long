/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 03:42:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_map(t_window win, char *filename)
{
	int	n_lines;
	char	**map;
	char  *line;
	int fd;
	int	l;
	int	i;
	int j;


	// ALLOCAZIONE COLONNE!!!--------------------------------
	n_lines = count_lines(filename);
	// ft_printf("n lines: %d\n", n_lines);
	map = ft_calloc(n_lines, sizeof(int));
	if (!map)
		return (ft_printf("Map not allocated properly\n"), 0);
	// ALLOCAZIONE RIGHE!!!-----------------------------------
	
	i = 0;
	if (!filename)
		return (ft_printf("File not provided\n"), 0);
	if (!is_valid_filename(filename))
		return (ft_printf("File is not valid\n"), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error in file opening\n"), 0);
	line = get_next_line(fd);
	while(line && i < n_lines)
	{
		j = 0;
		printf("%s\n", line);
		l = ft_strlen(line);
		map[i] = line;
		if (!map[i])
		{
			ft_printf("Allocation error\n");
			deallocate_map(map, i);
		}

		line = get_next_line(fd);
		i++;
	}
	close(fd);
}


void	deallocate_map(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
	}
	free(map);
}

