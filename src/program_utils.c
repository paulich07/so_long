/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/13 16:22:37 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_window *win, char *s)
{
	deallocate_map(win->map, win->map_height);
	// deallocate_map_copy(win->map_copy, win->map_height);
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
	if (s && ft_strlen(s) > 0)
		ft_printf("%s\n", s);
	exit(0);
}

int  close_window(t_window *win)
{
	exit_program(win, "Window closed");
	return (0);
}