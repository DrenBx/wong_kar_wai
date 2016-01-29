/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:37:52 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/01 17:50:06 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wong_kar_wai.h"

static void	reset_game(t_core *core)
{
	ft_free(core);
	core->tab = ft_init_tab(core->tab);
	core->save = ft_init_tab(core->save);
	core->tab = ft_random(core->tab);
	core->tab = ft_random(core->tab);
	clear_all_win(core);
	core->end_game = 0;
	core->winit = 0;
}

static int	do_key_action(t_core *core)
{
	int		key;

	key = 0;
	if ((key = getch()) != ERR)
	{
		if (key == 27)
			return (-1);
		if (core->end_game > 0 && (key == 'r' || key == 'R'))
			reset_game(core);
		else if (core->end_game == 2 && key == ' ')
			core->end_game = 0;
		if (key == KEY_UP)
			top(core);
		if (key == KEY_DOWN)
			bot(core);
		if (key == KEY_LEFT)
			left(core);
		if (key == KEY_RIGHT)
			right(core);
		if (ft_loose(core->tab) == 0)
			core->end_game = 1;
		return (1);
	}
	return (0);
}

static int	get_color_id(int value)
{
	int		i;
	int		pow;

	i = 2;
	pow = 1;
	while (i < value)
	{
		i *= 2;
		pow++;
	}
	return (pow);
}

static void	print_cases(t_core *core)
{
	int		x;
	int		y;
	t_slot	slot;

	y = -1;
	if (core->height < MINSIZE_Y || core->width < MINSIZE_X)
		return ;
	while (++y < core->board_size_y)
	{
		x = -1;
		while (++x < core->board_size_x)
		{
			slot = core->board[x][y];
			box(slot.win, 0, 0);
			if (core->tab[y][x] > 0)
			{
				wbkgd(slot.win, COLOR_PAIR(3 + get_color_id(core->tab[y][x])));
				mvwprintw(slot.win, slot.size_y / 2, \
						slot.size_x / 2, "%d", core->tab[y][x]);
			}
			wrefresh(slot.win);
		}
	}
}

void		game(void)
{
	t_core	core;
	int		key_action;

	init(&core);
	core.tab = ft_init_tab(core.tab);
	core.save = ft_init_tab(core.save);
	core.tab = ft_random(core.tab);
	core.tab = ft_random(core.tab);
	get_new_winsize(&core, 1);
	while (42)
	{
		get_new_winsize(&core, 0);
		key_action = do_key_action(&core);
		if (key_action == -1)
			break ;
		if (core.end_game == 0)
			print_cases(&core);
		menu(&core, 1);
		refresh();
	}
	ft_free(&core);
	endwin();
}
