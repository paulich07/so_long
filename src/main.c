/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/03/12 16:30:06 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    printf("is alpha: %d", ft_isalpha(97));

    void *mlx;
    void *win;

    // Inizializza la libreria mlx
    mlx = mlx_init();
    
    // Crea una finestra con dimensioni 800x600 e un titolo
    win = mlx_new_window(mlx, 800, 600, "Finestra Minilibx");

    // Colore di sfondo (rosso in RGB)
    mlx_clear_window(mlx, win);
    mlx_string_put(mlx, win, 10, 10, 0xFFFFFF, "Ciao Minilibx!");

    // Mantieni la finestra aperta fino a che non viene chiusa
    mlx_loop(mlx);

    return (0);
}