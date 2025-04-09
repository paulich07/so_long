/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:58 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 00:02:36 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE
#  define TILE 64
# endif

# include "libft.h"
# include "mlx.h"
// keysymdef in caso non prenda
#	include <X11/keysym.h>
#	include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	**map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// Texture per ogni elemento
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
} t_window;

// Hooks
int     key_press(int keycode, t_window *vars);

// Utils
void	render_map(t_window *game);
int	close_window(t_window *win);

#endif