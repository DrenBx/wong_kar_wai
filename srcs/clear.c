/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:13:54 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/01 18:37:13 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

void		clear_all_win(t_core *core)
{
	int		x;
	int		y;

	y = -1;
	while (++y < core->board_size_y)
	{
		x = -1;
		while (++x < core->board_size_x)
		{
			wclear((core->board[x][y]).win);
			wbkgd(core->board[x][y].win, COLOR_PAIR(0));
		}
	}
}
