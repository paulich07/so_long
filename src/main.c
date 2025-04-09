/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/09 21:24:33 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(void)
{
    t_window    win;
    // t_img       img;

    // Inizializza libreria
    win.mlx = mlx_init();
    if (!win.mlx)
        return (1);

    // Creo finestra
    win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, "so_long");
    if (!win.win)
        return (1);

    // STRING
    mlx_string_put(win.mlx, win.win, 10, 10, 0xFFFFFF, "Ciao Minilibx!");

    // IMAGE
    // img.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);
    // if (!img.img)
    //     return (1);

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