/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:35:39 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/09 17:25:50 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "wong_kar_wai.h"

static void	init_ncurses_colors(void)
{
	int		i;
	int		j;

	i = 3;
	j = 10 * 20;
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_RED);
	while (++i < 20)
	{
		init_pair(i, COLOR_BLACK, j);
		j -= 10;
	}
}

static void	init_ncurses(t_core *core)
{
	initscr();
	getmaxyx(stdscr, core->height, core->width);
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	init_ncurses_colors();
}

static void	interupt_handler(int sig_number)
{
	(void)sig_number;
	endwin();
	exit(0);
}

static void	get_victory_condition(t_core *core)
{
	int		i;

	i = 8;
	while (i < WIN_VALUE)
		i *= 2;
	core->victory_condition = (WIN_VALUE - i) == 0 ? WIN_VALUE : 2048;
}

void		init(t_core *core)
{
	signal(SIGINT, interupt_handler);
	core->board_size_x = 4;
	core->board_size_y = 4;
	core->width = 0;
	core->height = 0;
	core->winit = 0;
	core->end_game = 0;
	get_victory_condition(core);
	init_ncurses(core);
}
