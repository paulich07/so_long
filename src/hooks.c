/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 15:35:53 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_window *win)
{
	(void)win;
	if (keycode == XK_Escape)
	{
		exit_program(win);
	}
	if (keycode == XK_Left)
	{
		printf("Freccia sinistra!\n");
		move_player(win, -1, 0);
	}
	if (keycode == XK_Right)
	{
		printf("Freccia destra!\n");
		move_player(win, 1, 0);
	}
	if (keycode == XK_Up)
	{
		printf("Freccia su!\n");
		move_player(win, 0, -1);
	}
	if (keycode == XK_Down)
	{
		printf("Freccia giù!\n");
		move_player(win, 0, 1);
	}
	return (1);
}