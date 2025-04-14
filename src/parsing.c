/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:38:05 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 18:54:34 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief check if filename ends with ".ber"
/// @param filename string that contains the name of the file of the map
/// @return boolean 1 is valid or 0 not valid
int	is_valid_filename(char *filename)
{
	if (!filename)
		return (0);
	if (ft_strlen(filename) < 4)
		return (0);
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".ber", 4) != 0)
		return (0);
	return (1);
}

/// @brief check if the filename is a directory
/// @param filename string that contains the name of the file of the map
/// @return boolean 1 is valid or 0 not valid
int	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd < 0)
		return (0);
	return (close(fd), 1);
}

/// @brief check that every line has the same length of the first one
/// @param win structure that contains literally everything
/// @param fd file descriptor (already open)
/// @param l first line (already read);
/// @return 1 if the size i the same, 0 otherwise
int	check_every_line(t_window *win, int fd, char **l)
{
	char *line;
	
	line = *l;
	while (line)
	{
		win->map_height++;
		if (ft_strlen(line) <= 0)
			return (free(line), 0);
		if (line[(ft_strlen(line)) - 1] == '\n')
			line[(ft_strlen(line)) - 1] = '\0';
		if ((int)(ft_strlen(line)) != win->map_width)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

/// @brief calculate height and width of the map,
/// @brief check if the map is rectangular
/// @param win window structure that contains everything
/// @param filename string that contains the name of the file of the map
/// @return bool 1 if is rectangular or 0 otherwise
int	is_valid_map_size(t_window *win, char *filename)
{
	char	*line;
	int		fd;

	if (!filename)
		exit_program(win, "Filename not provided");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Cannot open file");
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	if (ft_strlen(line) <= 0)
		return (free(line), 0);
	if (line[(ft_strlen(line)) - 1] == '\n')
		line[(ft_strlen(line)) - 1] = '\0';
	win->map_width = ft_strlen(line);
	if (!check_every_line(win, fd, &line))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
