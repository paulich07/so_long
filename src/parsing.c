/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:38:05 by plichota          #+#    #+#             */
/*   Updated: 2025/04/12 00:06:42 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_filename(char *filename)
{
  if (!filename)
    return (0);
  return (1);
}

int count_lines(char *filename)
{
  int fd;
  int count;
  char  *line;

  if (!filename)
    return (ft_printf("File not provided\n"), 0);
  if (!is_valid_filename(filename))
    return (ft_printf("File is not valid\n"), 0);
  fd = open(filename, O_RDONLY);
  if (fd < 0)
    return (ft_printf("Error in file opening\n"), 0);
  count = 0;
  line = get_next_line(fd);
  while(line)
  {
    count++;
    free(line);
    // printf("%s\n", line);
    line = get_next_line(fd);
  }
  free(line);
  close(fd);
  return (count);
}
