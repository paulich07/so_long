/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/11 21:05:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_window *win)
{
	deallocate_map(win->map);
	if (win->img_floor)
    mlx_destroy_image(win->mlx, win->img_floor);
	if (win->img_wall)
			mlx_destroy_image(win->mlx, win->img_wall);
	if (win->img_player)
			mlx_destroy_image(win->mlx, win->img_player);
	if (win->img_collect)
			mlx_destroy_image(win->mlx, win->img_collect);
	if (win->img_exit)
			mlx_destroy_image(win->mlx, win->img_exit);
	if (win->win)
			mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
			mlx_destroy_display(win->mlx);
			free(win->mlx);
	}
	write(2, "Exit\n", 5);
	exit(0);
}

int  close_window(t_window *win)
{
	exit_program(win);
	return (0);
}