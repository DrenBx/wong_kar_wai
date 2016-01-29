/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalb <fkalb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:32:54 by fkalb             #+#    #+#             */
/*   Updated: 2015/03/01 17:50:16 by fkalb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_kar_wai.h"

static int	get_score(t_core *core)
{
	int		x;
	int		y;
	int		score;

	y = -1;
	score = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			score += core->tab[y][x];
	}
	return (score);
}

static void	end_menu(t_core *core)
{
	if (core->end_game == 2)
	{
		clear();
		attron(COLOR_PAIR(1));
		mvwprintw(stdscr, 0, 0, "You win! - Score : %d", get_score(core));
		mvwprintw(stdscr, 1, 0, "'space' for continue");
		mvwprintw(stdscr, 2, 0, "'R' for restart");
		mvwprintw(stdscr, 3, 0, "'esc' for exit");
		attroff(COLOR_PAIR(1));
	}
	else if (core->end_game)
	{
		clear();
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, 0, 0, "You lose! - Score : %d", get_score(core));
		mvwprintw(stdscr, 1, 0, "'R' for restart");
		mvwprintw(stdscr, 2, 0, "'esc' for exit");
		attroff(COLOR_PAIR(2));
	}
}

void		menu(t_core *core, int menu)
{
	if (menu == 1)
		end_menu(core);
}
