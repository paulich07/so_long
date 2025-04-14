/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/14 18:36:44 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_window *win)
{
	if (keycode == XK_Escape)
		exit_program(win, "Exit");
	else if (keycode == XK_Left)
	{
		printf("Freccia sinistra!\n");
		move_player(win, -1, 0);
	}
	else if (keycode == XK_Right)
	{
		printf("Freccia destra!\n");
		move_player(win, 1, 0);
	}
	else if (keycode == XK_Up)
	{
		printf("Freccia su!\n");
		move_player(win, 0, -1);
	}
	else if (keycode == XK_Down)
	{
		printf("Freccia giù!\n");
		move_player(win, 0, 1);
	}
	return (1);
}

int	close_window(t_window *win)
{
	exit_program(win, "Window closed");
	return (0);
}
