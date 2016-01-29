/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:32:22 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/01 18:34:49 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static void	set_slots(t_core *core, short int first_time)
{
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	t_slot	slot;

	y = -1;
	size_x = core->width / core->board_size_x;
	size_y = core->height / core->board_size_y;
	while (++y < core->board_size_y)
	{
		x = -1;
		while (++x < core->board_size_y)
		{
			slot = core->board[x][y];
			if (first_time)
				slot.value = 0;
			slot.pos_x = size_x * x;
			slot.pos_y = size_y * y;
			delwin(slot.win);
			slot.win = newwin(size_y, size_x, size_y * y, size_x * x);
			getmaxyx(slot.win, slot.size_y, slot.size_x);
			core->board[x][y] = slot;
		}
	}
}

static void	resize(t_core *core, int w, int h)
{
	clear_all_win(core);
	clear();
	if (w < MINSIZE_X || h < MINSIZE_Y)
		mvwprintw(stdscr, 0, 0, "The window are too small!");
	else
		set_slots(core, 0);
}

void		get_new_winsize(t_core *core, short int first_time)
{
	int		h;
	int		w;

	getmaxyx(stdscr, h, w);
	if (!first_time)
	{
		if (w == -1 || h == -1)
		{
			clear();
			mvwprintw(stdscr, 0, 0, "An error was occured!");
			return ;
		}
		if (w == core->width && h == core->height)
			return ;
		resize(core, w, h);
	}
	else
	{
		set_slots(core, 1);
		if (w < MINSIZE_X || h < MINSIZE_Y)
			mvwprintw(stdscr, 0, 0, "The window are too small!");
	}
	core->height = h;
	core->width = w;
}
