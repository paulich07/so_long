/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/10 15:42:45 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_window *win)
{
	deallocate_map(win->map);
	write(1, "Exit\n", 5);
	exit(0);
}