/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/09 22:09:06 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// @brief 
/// @param keycode 
/// @param vars 
/// @return 1
int key_press(int keycode, t_window *vars)
{
	(void)vars;
	if (keycode == XK_Escape)
	{
		write(1, "Programma terminato dall'utente.\n", 34);
		exit(0);
	}
	if (keycode == XK_Left)
		printf("Freccia sinistra!\n");
	if (keycode == XK_Right)
		printf("Freccia destra!\n");
	if (keycode == XK_Up)
		printf("Freccia su!\n");
	if (keycode == XK_Down)
		printf("Freccia giù!\n");
	return (1);
}