/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 00:57:19 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief 
/// @param keycode 
/// @param vars 
/// @return 1
int key_press(int keycode, t_window *win)
{
	(void)win;
	if (keycode == XK_Escape)
	{
		write(1, "Exit\n", 5);
		exit(0);
	}
	if (keycode == XK_Left)
	{
		// printf("walkable: %d\n", is_walkable(win, win->pos_x - 1, win->pos_y));
		printf("Freccia sinistra!\n");
		// win->pos_x--;
	}
	if (keycode == XK_Right)
	{
		// printf("walkable: %d\n", is_walkable(win, win->pos_x + 1, win->pos_y));
		printf("Freccia destra!\n");
	}
	if (keycode == XK_Up)
		printf("Freccia su!\n");
	if (keycode == XK_Down)
		printf("Freccia giù!\n");
	return (1);
}