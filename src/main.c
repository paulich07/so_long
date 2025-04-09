/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/09 23:56:36 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(void)
{
	t_window    win;
	int map_width;
	int map_height;
	int img_width;
	int img_height;
	
	char *map[] = {
		"11111",
		"1P0C1",
		"1E001",
		"11111",
		NULL
	};
	win.map = map;

	// Inizializza libreria
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);
	
	map_width = ft_strlen(map[0]);
	map_height = 0;
	while (map[map_height])
		map_height++;

	// Creo finestra
	win.win = mlx_new_window(win.mlx, map_width * TILE, map_height * TILE, "so_long");
	if (!win.win)
		return (1);

	// STRING
	mlx_string_put(win.mlx, win.win, 10, 10, 0xFFFFFF, "Ciao Minilibx!");

	// IMAGE
	img_width = TILE;
	img_height = TILE;

	win.img_floor = mlx_xpm_file_to_image(win.mlx, "textures/floor.xpm", &img_width, &img_height);
	win.img_wall = mlx_xpm_file_to_image(win.mlx, "textures/wall.xpm", &img_width, &img_height);
	win.img_player = mlx_xpm_file_to_image(win.mlx, "textures/player.xpm", &img_width, &img_height);
	win.img_collect = mlx_xpm_file_to_image(win.mlx, "textures/collect.xpm", &img_width, &img_height);
	win.img_exit = mlx_xpm_file_to_image(win.mlx, "textures/exit.xpm", &img_width, &img_height);

	if (!win.img_floor || !win.img_wall || !win.img_player || !win.img_collect || !win.img_exit)
	{
		write(2, "Errore nel caricamento delle immagini\n", 39);
		exit(1);
	}

	render_map(&win);

	// pixels = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);

	// for (int y = 250; y < 250 + SQUARE_SIZE; y++) {
	//     for (int x = 350; x < 350 + SQUARE_SIZE; x++) {
	//         // Fill the square with red (in ARGB format)
	//         pixels[y * WIDTH + x] = 0x00FF0000; // 0x00FF0000 is red
	//     }
	// }

	// mlx_put_image_to_window(mlx, win, img, 0, 0);

	// HOOK
	mlx_key_hook(win.win, key_press, NULL);

	// mlx_clear_window(mlx, win);
	mlx_loop(win.mlx);

	return (0);
}