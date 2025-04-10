/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:58 by plichota          #+#    #+#             */
/*   Updated: 2025/04/12 00:43:47 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE
#  define TILE 64
# endif

# include "libft.h"
# include "mlx.h"
#	include <X11/keysym.h>
#	include <X11/X.h>
# include <fcntl.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
	char	**map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		pos_x;
	int		pos_y;
	int		map_height;
	int		map_width;
	// Coins
	int		n_coins;
	int		n_collected_coins;
} t_window;

// Hooks
int		key_press(int keycode, t_window *vars);

// Parsing
int		count_lines(char *filename);
int		is_valid_filename(char *filename);

// Utils
void	render_map(t_window *win);
int		is_walkable(t_window *win, int x, int y);
void	count_coins(t_window *win);

// Player Utils
void	initialize_player_position(t_window *win);
void	move_player(t_window *win, int move_x, int move_y);
int		all_coins_collected(t_window *win);
int		is_exit(t_window *win, int pos_y, int pos_x);

// Program Utils
void	exit_program(t_window *win, char *s);
int		close_window(t_window *win);

// Map Utils
char **allocate_map(char *filename, t_window *win);
void	deallocate_map(char **map);

#endif