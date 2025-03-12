/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/03/12 18:58:07 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx;
    void    *win;

    void    *img;
    int     *pixels;
    int     bpp;
    int     size_line;
    int     endian;

    mlx = mlx_init();
    if (!mlx)
        return (-1);

    win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");

    // mlx_string_put(mlx, win, 10, 10, 0xFFFFFF, "Ciao Minilibx!");

    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    pixels = (int *)mlx_get_data_addr(img, &bpp, &size_line, &endian);
    
    for (int y = 250; y < 250 + SQUARE_SIZE; y++) {
        for (int x = 350; x < 350 + SQUARE_SIZE; x++) {
            // Fill the square with red (in ARGB format)
            pixels[y * WIDTH + x] = 0x00FF0000; // 0x00FF0000 is red
        }
    }
    
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // mlx_clear_window(mlx, win);
    mlx_loop(mlx);

    return (0);
}