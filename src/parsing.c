/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:38:05 by plichota          #+#    #+#             */
/*   Updated: 2025/04/13 10:29:58 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief check if filename ends with ".ber"
/// @param filename string that contains the name of the file of the map
/// @return boolean 1 is valid or 0 not valid
int is_valid_filename(char *filename)
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
int is_directory(char *filename)
{
  int fd;

  fd = open(filename, O_DIRECTORY);
  if (fd < 0)
    return (0);
  return (close(fd), 1);
}

/// @brief count number of lines in the file and set the map_height in the struct
/// @param win window structure that contains everything
/// @param filename string that contains the name of the file of the map
/// @return number of lines = height of the map
int count_lines(t_window *win, char *filename)
{
  int fd;
  char  *line;

  win->map_height = 0;
  line = NULL;
  // ft_printf("count lines\n");  
  if (!filename)
    exit_program(win, "Filename not provided");
  fd = open(filename, O_RDONLY);
  if (fd < 0)
    exit_program(win, "Cannot open file");
  line = get_next_line(fd);
  while(line)
  {
    win->map_height++;
    free(line);
    // printf("%s\n", line);
    line = get_next_line(fd);
  }
  free(line);
  close(fd);
  return (win->map_height);
}
