/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/12 00:46:01 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_window    win;
	char	**map;
	char	*filename;
	int img_width;
	int img_height;

	filename = "maps/map.ber";

	// Parsing mappa
	// ---- to do here

	map = allocate_map(filename, &win);
	if (!map)
		exit_program(&win, "Map not allocated properly");
	win.map = map;

	win.n_collected_coins = 0;
	win.n_coins = 0;
	count_coins(&win);

	// Inizializza libreria
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);
	
	win.map_width = ft_strlen(map[0]);
	win.map_width--;
	win.map_height = 0;
	while (map[win.map_height])
		win.map_height++;

	initialize_player_position(&win);
	// printf("pos y %d\n", win.pos_y);
	// printf("pos x %d\n", win.pos_x);

	// Creo finestra
	win.win = mlx_new_window(win.mlx, win.map_width * TILE, win.map_height * TILE, "so_long");
	if (!win.win)
		exit_program(&win, "Window not loaded properly");

	// STRING
	// mlx_string_put(win.mlx, win.win, 10, 10, 0xFFFFFF, "Ciao Minilibx!");

	// IMAGE
	img_width = TILE;
	img_height = TILE;

	win.img_floor = mlx_xpm_file_to_image(win.mlx, "textures/floor.xpm", &img_width, &img_height);
	win.img_wall = mlx_xpm_file_to_image(win.mlx, "textures/wall.xpm", &img_width, &img_height);
	win.img_player = mlx_xpm_file_to_image(win.mlx, "textures/player.xpm", &img_width, &img_height);
	win.img_collect = mlx_xpm_file_to_image(win.mlx, "textures/collect.xpm", &img_width, &img_height);
	win.img_exit = mlx_xpm_file_to_image(win.mlx, "textures/exit.xpm", &img_width, &img_height);

	if (!win.img_floor || !win.img_wall || !win.img_player || !win.img_collect || !win.img_exit)
		exit_program(&win, "Image not loaded properly");

	render_map(&win);

	// pixels = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);

	// for (int y = 250; y < 250 + SQUARE_SIZE; y++) {
	//     for (int x = 350; x < 350 + SQUARE_SIZE; x++) {
	//         // Fill the square with red (in ARGB format)
	//         pixels[y * WIDTH + x] = 0x00FF0000; // 0x00FF0000 is red
	//     }
	// }

	// mlx_put_image_to_window(mlx, win, img, 0, 0);

	// Hook keys
	mlx_key_hook(win.win, key_press, &win);

	// Hook cursor
	// 17 = evento DestroyNotify (quando clicchi la X)
	// 0 = mask
	mlx_hook(win.win, 17, 0, close_window, &win);

	// mlx_clear_window(mlx, win);
	mlx_loop(win.mlx);
	return (0);
}
