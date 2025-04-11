/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:04:10 by plichota          #+#    #+#             */
/*   Updated: 2025/04/11 21:46:24 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// alloco prima y altezza (numero di righe)
// poi x (lunghezza)
void	initialize_player_position(t_window *win)
{
	int x;
	int y;

	y = 0;
	while (y < win->map_height)
	{
    x = 0;
    while (x < win->map_width)
    {
        if (win->map[y][x] == 'P')
        {
            win->pos_x = x;
            win->pos_y = y;
            return ;
        }
        x++;
			}
			y++;
    }
		printf("pos y %d\n", win->pos_y);
		printf("pos x %d\n", win->pos_x);
}

void	move_player(t_window *win, int move_x, int move_y)
{
  if (is_walkable(win, win->pos_x + move_x, win->pos_y + move_y)
    && !is_exit(win, win->pos_y + move_y, win->pos_x + move_x))
  {
    if (win->map[win->pos_y][win->pos_x] == 'C')
      win->n_collected_coins++;

    printf("is walkable\n");
    win->map[win->pos_y][win->pos_x] = '0';
    win->pos_x += move_x;
    win->pos_y += move_y;
    win->map[win->pos_y][win->pos_x] = 'P';
    render_map(win);

    if (is_exit(win, win->pos_y, win->pos_x) && all_coins_collected(win))
      exit_program(win);
  }
  else
    printf("not walkable\n");
}

int	all_coins_collected(t_window *win)
{
	if (!win || !win->n_coins || !win->n_collected_coins)
		return (0);
	return (win->n_coins == win->n_collected_coins);
}

int	is_exit(t_window *win, int pos_y, int pos_x)
{
  if (win->map[pos_y][pos_x] == 'E')
    return (1);
	return (0);
}