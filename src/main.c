/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 14:28:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
int main(int argc, char *argv[])
{
	t_window    win = {0};
	char	*filename;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long <map.ber>\n"), 1);
	filename = argv[1];
	if (!is_valid_filename(filename))
		return (ft_printf("Invalid file format\n"), 1);
	if (is_directory(filename))
		return (ft_printf("Directory instead of file provided\n"), 1);

	win.map = allocate_map(&win, filename);
	if (!win.map || !*win.map)
		exit_program(&win, "Map not allocated properly");
	// win.map = map;

	// --------------------------Parsing mappa
	// creo copia matrice
	
	// copy_map(&win);
	
	// controllo walls
	// controllo players/collectables/exit e caratteri non validi
	// flood fill a partire da pos player mentre raccolgo collectables, ed exit
	
	

	// win.n_collected_coins = 0;
	// win.n_coins = 0;
	count_coins(&win);

	// Inizializza libreria
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);
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
	put_images(&win);
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
